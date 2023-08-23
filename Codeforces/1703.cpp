#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

vector<int> adj[N];
int par[N][25], dep[N];
int seen[N], inst[N], idom[N];

void chmin(int &a, int b) {
  if (a > b) a = b;
}

void dfs1(int i) {
  seen[i] = 1;
  for (int j = 1; j <= 20; j++) {
    par[i][j] = par[par[i][j - 1]][j - 1];
  }
  for (auto &j : adj[i]) {
    if (!seen[j]) {
      par[j][0] = i;
      dep[j] = dep[i] + 1;
      dfs1(j);
    }
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

void dfs2(int i) {
  seen[i] = inst[i] = 1;
  for (auto &j : adj[i]) {
    if (inst[j]) {
      
    }
    if (!seen[j]) dfs2(j);
  }
  inst[i] = 0;
}

void dfs3(int i) {
  seen[i] = 1;
  for (auto &j : adj[i]) {

  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  freopen("in" , "r", stdin );
  freopen("out", "w", stdout);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
  }
  dep[1] = 1;
  dfs1(1);
  memset(seen, 0, sizeof(seen));
  for (int i = 1; i <= n; i++) {
    idom[i] = i;
  }
  dfs2(1);
  memset(seen, 0, sizeof(seen));
  dfs3(1);
}
