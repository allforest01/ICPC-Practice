#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
const int block_sz = sqrt(N);

vector<int> adj[N], red;
int par[N][25], dep[N], best[N];

void dfs(int i, int p) {
  for (auto &j : adj[i]) {
    if (j == p) continue;
    par[j][0] = i;
    dep[j] = dep[i] + 1;
    dfs(j, i);
  }
}

int lca(int u, int v) {
  if (dep[u] < dep[v]) swap(u, v);
  for (int j = 20; j >= 0; j--) {
    if (dep[par[u][j]] >= dep[v]) {
      u = par[u][j];
    }
  }
  if (u == v) return u;
  for (int j = 20; j >= 0; j--) {
    if (par[u][j] != par[v][j]) {
      u = par[u][j];
      v = par[v][j];
    }
  }
  return par[u][0];
}

int dist(int u, int v) {
  return dep[u] + dep[v] - 2 * dep[lca(u, v)];
}

int bfs() {
  queue<array<int,2>> q;
  for (auto &i : red) q.push({i, 0});
  while (q.size()) {
    auto i = q.front(); q.pop();
    if (best[i[0]] <= i[1]) continue;
    best[i[0]] = i[1];
    for (auto &j : adj[i[0]]) {
      q.push({j, i[1] + 1});
    }
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, q;
  cin >> n >> q;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dep[1] = 1;
  dfs(1, -1);
  for (int j = 1; j <= 20; j++)
  for (int i = 1; i <= n; i++) {
    par[i][j] = par[par[i][j - 1]][j - 1];
  }
  memset(best, 0x3f, sizeof(best));
  red.push_back(1);
  while (q--) {
    int t, x;
    cin >> t >> x;
    if (t == 1) {
      red.push_back(x);
      if (red.size() > block_sz) {
        bfs();
        red.clear();
      }
    }
    else {
      int ans = best[x];
      for (auto &i : red) {
        ans = min(ans, dist(x, i));
      }
      cout << ans << '\n';
    }
  }
}
