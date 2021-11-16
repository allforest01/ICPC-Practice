#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

vector<int> adj[N];
int par[N][20], dep[N];

void dfs(int i, int p) {
  par[i][0] = p;
  for (int j = 1; j < 20; j++) {
    par[i][j] = par[par[i][j - 1]][j - 1];
  }
  for (auto &j : adj[i]) {
    if (j != p) {
      dep[j] = dep[i] + 1;
      dfs(j, i);
    }
  }
}

int dist(int u, int v) {
  // cout << u << ' ' << v << '\n';
  int ret = 0;
  if (dep[u] > dep[v]) swap(u, v);
  for (int j = 19; j >= 0; j--) {
    if (dep[par[v][j]] >= dep[u]) {
      ret += (1 << j);
      v = par[v][j]; 
      // cout << u << ' ' << v << ' ' << ret << '\n';
    }
  }
  // cout << u << ' ' << v << '\n';
  if (u == v) return ret;
  for (int j = 19; j >= 0; j--) {
    if (par[u][j] != par[v][j]) {
      ret += (1 << (j + 1));
      u = par[u][j];
      v = par[v][j];
      // cout << u << ' ' << v << ' ' << ret << '\n';
    }
  }
  ret += 2;
  return ret;
}

int main() {
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
  dfs(1, 0);
  while (q--) {
    int u, v;
    cin >> u >> v;
    // cout << '\n';
    int d = dist(u, v);
    // cout << '\n';
    // cout << u << ' ' << v << ' ' << d << '\n';
    if (d % 2) cout << "Road" << '\n';
    else cout << "Town" << '\n';
  }
}
