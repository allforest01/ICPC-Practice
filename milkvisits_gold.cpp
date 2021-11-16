#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

vector<int> adj[N], ver[N];
vector<array<int,3>> qr[N];
int tin[N], tout[N], timer = 0;
int par[N][20], dep[N];

struct BIT {
  int n; vector<int> bit;
  BIT(int n): n(n), bit(n + 1) {}
  void update(int i, int val) {
    for (; i <= n; i += i & -i) {
      bit[i] += val;
    }
  }
  int get(int i) {
    int val = 0;
    for (; i; i -= i & -i) {
      val += bit[i];
    }
    return val;
  }
  void update(int u, int v, int val) {
    update(u, val);
    update(v + 1, -val);
  }
};

void dfs(int i, int p) {
  for (int j = 1; j < 20; j++) {
    par[i][j] = par[par[i][j - 1]][j - 1];
  }
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
  for (int j = 19; j >= 0; j--) {
    if (dep[par[u][j]] >= dep[v]) {
      u = par[u][j];
    }
  }
  if (u == v) return u;
  for (int j = 19; j >= 0; j--) {
    if (par[u][j] != par[v][j]) {
      u = par[u][j];
      v = par[v][j];
    }
  }
  return par[u][0];
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  freopen("milkvisits.in" , "r", stdin );
  freopen("milkvisits.out", "w", stdout);
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    ver[x].push_back(i);
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (int i = 1; i <= q; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    qr[c].push_back({u, v, i});
  }
  dep[1] = 1;
  dfs(1, -1);
  BIT bit(n);
  vector<int> res(n + 1);
  for (int i = 1; i <= n; i++) {
    for (auto &v : ver[i]) {
      bit.update(tin[v], tout[v], 1);
    }
    for (auto &j : qr[i]) {
      int u = j[0], v = j[1], p = j[2];
      int l = lca(u, v);
      res[p] = (bit.get(tin[u]) + bit.get(tin[v])
        - bit.get(tin[l]) - bit.get(tin[par[l][0]])) != 0;
    }
    for (auto &v : ver[i]) {
      bit.update(tin[v], tout[v], -1);
    }
  }
  for (int i = 1; i <= q; i++) {
    cout << res[i];
  }
  cout << '\n';
}
