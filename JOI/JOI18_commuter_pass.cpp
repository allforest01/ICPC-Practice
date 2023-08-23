#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 100005;

int n, m, s, t, u, v;
vector<pair<ll,int>> adj[N];

bool minself(ll &a, ll b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

void dijkstra(int start, vector<ll> &dist) {
  vector<int> vst(n + 1);
  dist.assign(n + 1, 1e15);
  dist[start] = 0;
  priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
  pq.push(make_pair(0, start));
  while (pq.size()) {
    auto i = pq.top(); pq.pop();
    if (vst[i.second]) continue;
    vst[i.second] = 1;
    for (auto &j : adj[i.second]) {
      ll comp = i.first + j.first;
      if (comp < dist[j.second]) {
        dist[j.second] = comp;
        pq.push(make_pair(comp, j.second));
      }
    }
  }
}

// S == U
namespace sub1 {
  void Main() {
    vector<ll> s_dist, v_dist, t_dist;
    dijkstra(s, s_dist);
    dijkstra(v, v_dist);
    dijkstra(t, t_dist);
    ll ans = s_dist[v];
    for (int i = 1; i <= n; i++) {
      if (s_dist[i] + t_dist[i] == s_dist[t]) {
        minself(ans, v_dist[i]);
      }
    }
    cout << ans << '\n';
  }
}

// n <= 300
namespace sub3 {
  void Main() {
    vector<vector<ll>> mat_dist(n + 1, vector<ll>(n + 1, 1e15));
    for (int i = 1; i <= n; i++) {
      mat_dist[i][i] = 0;
      for (auto &j : adj[i]) {
        mat_dist[i][j.second] = mat_dist[j.second][i] = j.first;
      }
    }
    for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      minself(mat_dist[i][j], mat_dist[i][k] + mat_dist[k][j]);
    }
    ll ans = mat_dist[u][v];
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      if (mat_dist[s][i] + mat_dist[i][j] + mat_dist[j][t] == mat_dist[s][t]) {
        minself(ans, mat_dist[u][i] + mat_dist[j][v]);
        minself(ans, mat_dist[u][j] + mat_dist[i][v]);
      }
    }
    cout << ans << '\n';
  }
}

// unique min path s -> t
namespace sub2 {
  void Main() {
    vector<ll> s_dist;
    dijkstra(s, s_dist);
    int tmp = t;
    while (tmp != s) {
      for (auto &j : adj[tmp]) {
        if (s_dist[j.second] + j.first == s_dist[tmp]) {
          j.first = 0;
          for (auto &k : adj[j.second]) {
            if (k.second == tmp) {
              k.first = 0;
              break;
            }
          }
          tmp = j.second;
          break;
        }
      }
    }
    vector<ll> u_dist;
    dijkstra(u, u_dist);
    cout << u_dist[v] << '\n';
  }
}

namespace sub4 {
  void Main() {
    vector<ll> u_dist, v_dist, s_dist;
    dijkstra(u, u_dist);
    dijkstra(v, v_dist);
    dijkstra(s, s_dist);
    vector<ll> ok(n + 1);
    queue<int> q; q.push(t);
    while (q.size()) {
      int i = q.front(); q.pop();
      ok[i] = 1;
      for (auto &j : adj[i]) {
        if (!ok[j.second] && j.first == s_dist[i] - s_dist[j.second]) {
          q.push(j.second);
        }
      }
    }
    vector<pair<ll,int>> vec;
    for (int i = 1; i <= n; i++) {
      vec.push_back(make_pair(s_dist[i], i));
    }
    vector<ll> dpu(n + 1, 1e15), dpv(n + 1, 1e15);
    sort(vec.begin(), vec.end());
    for (auto &i : vec) {
      if (ok[i.second]) {
        minself(dpu[i.second], u_dist[i.second]);
        minself(dpv[i.second], v_dist[i.second]);
        for (auto &j : adj[i.second]) {
          if (ok[j.second] && j.first == s_dist[j.second] - s_dist[i.second]) {
            minself(dpu[j.second], dpu[i.second]);
            minself(dpv[j.second], dpv[i.second]);
          }
        }
      }
    }
    ll ans = u_dist[v];
    for (int i = 1; i <= n; i++) {
      minself(ans, u_dist[i] + dpv[i]);
      minself(ans, v_dist[i] + dpu[i]);
    }
    cout << ans << '\n';
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m >> s >> t >> u >> v;
  for (int i = 1; i <= m; i++) {
    int u, v; ll c;
    cin >> u >> v >> c;
    adj[u].push_back(make_pair(c, v));
    adj[v].push_back(make_pair(c, u));
  }
  /*if (s == u) sub1::Main();
  else if (n <= 300) sub3::Main();
  else*/ sub4::Main();
}
