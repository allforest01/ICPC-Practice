#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

vector<array<int,2>> adj[N];
int par[N][25], dep[N], dis[N];

void dfs(int i, int p) {
  for (auto &j : adj[i]) {
    if (j[1] == p) continue;
    par[j[1]][0] = i;
    dep[j[1]] = dep[i] + 1;
    dis[j[1]] = dis[i] + j[0];
    dfs(j[1], i);
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

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, q;
  cin >> n >> q;
  for (int i = 1; i < n; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({w, v});
    adj[v].push_back({w, u});
  }
  dep[1] = 1;
  dfs(1, -1);
  for (int j = 1; j <= 20; j++)
  for (int i = 1; i <= n; i++) {
    par[i][j] = par[par[i][j - 1]][j - 1];
  }
  while (q--) {
    int u, v;
    cin >> u >> v;
    cout << dis[u] + dis[v] - dis[lca(u, v)] * 2 << '\n';
  }
}