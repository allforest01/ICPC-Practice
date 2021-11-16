#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

vector<int> adj[N];
int n, a[N], par[N][20], dep[N];
int tin[N], tout[N], timer = 0;

struct Bit {
  int n; vector<int> bit;
  Bit(int n): n(n), bit(n + 1) {}
  void update(int i, int v) {
    for (; i <= n; i += i & -i) {
      bit[i] ^= v;
    }
  }
  int get(int i) {
    int v = 0;
    for (; i; i -= i & -i) {
      v ^= bit[i];
    }
    return v;
  }
} bit(N);

int dfs(int i, int p) {
  tin[i] = ++timer;
  for (auto &j : adj[i]) {
    if (j != p) {
      par[j][0] = i;
      dep[j] = dep[i] + 1;
      dfs(j, i);
    }
  }
  tout[i] = timer;
}

int lca(int u, int v) {
  if (dep[u] < dep[v]) swap(u, v);
  for (int i = 19; i >= 0; i--) {
    if (dep[par[u][i]] >= dep[v]) {
      u = par[u][i];
    }
  }
  if (u == v) return u;
  for (int i = 19; i >= 0; i--) {
    if (par[u][i] != par[v][i]) {
      u = par[u][i];
      v = par[v][i];
    }
  }
  return par[u][0];
}

void update(int i, int v) {
  bit.update(tin[i], a[i] ^ v);
  bit.update(tout[i] + 1, a[i] ^ v);
  a[i] = v;
}

int get(int u, int v) {
  return bit.get(tin[u]) ^ bit.get(tin[v]) ^ a[lca(u, v)];
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  freopen("cowland.in" , "r", stdin );
  freopen("cowland.out", "w", stdout);
  int q;
  cin >> n >> q;
  vector<int> tmp(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> tmp[i];
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dep[1] = 1;
  dfs(1, -1);
  for (int j = 1; j < 20; j++)
  for (int i = 1; i <= n; i++) {
    par[i][j] = par[par[i][j - 1]][j - 1];
  }
  for (int i = 1; i <= n; i++) {
    update(i, tmp[i]);
  }
  for (int i = 1; i <= q; i++) {
    int t, u, v;
    cin >> t >> u >> v;
    if (t == 1) {
      update(u, v);
    }
    else {
      cout << get(u, v) << '\n';
    }
  }
}
