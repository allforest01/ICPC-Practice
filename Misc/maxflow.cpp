#include <bits/stdc++.h>
using namespace std;

const int N = 505;

int n, m, s, t;
vector<int> adj[N];
int capa[N][N], flow[N][N], level[N];

bool bfs(int f) {
  memset(level, 0, sizeof(level));
  queue<int> q; q.push(s); level[s] = 1;
  bool flag = 0;
  while (q.size()) {
    int i = q.front(); q.pop();
    if (i == t) flag = 1;
    for (auto &j : adj[i]) {
      if (!level[j] && capa[i][j] - flow[i][j] >= f) {
        level[j] = level[i] + 1;
        q.push(j);
      }
    }
  }
  return flag;
}

bool dfs(int i, int f) {
  if (i == t) return true;
  for (auto &j : adj[i]) {
    if (level[j] == level[i] + 1 && capa[i][j] - flow[i][j] >= f) {
      flow[i][j] += f;
      flow[j][i] -= f;
      if (dfs(j, f)) return true;
      flow[i][j] -= f;
      flow[j][i] += f;
    }
  }
  return false;
}

int main() {
  cin >> n >> m >> s >> t;
  vector<array<int,2>> edges(m);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    edges[i] = {u, v};
    adj[u].push_back(v);
    adj[v].push_back(u);
    capa[u][v] += w;
  }
  int ans = 0;
  for (int f = (1 << 30); f; f >>= 1) {
    while (bfs(f)) {
      while (dfs(s, f)) {
        ans += f;
      }
    }
  }
  int cnt = 0;
  for (auto &e : edges) {
    if (flow[e[0]][e[1]] > 0) cnt++;
  }
  cout << n << ' ' << ans << ' ' << cnt << '\n';
  for (auto &e : edges) {
    int u = e[0], v = e[1];
    if (flow[u][v] > 0) {
      cout << u << ' ' << v << ' ' << flow[u][v] << '\n';
    }
  }
}