#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

vector<int> adj[N];
int cnt[N], rem[N], par_centroid[N], best[N];
int par[N][25], dep[N];

void dfs(int i, int p) {
  cnt[i] = 1;
  for (auto &j : adj[i]) {
    if (j == p || rem[j]) continue;
    dfs(j, i);
    cnt[i] += cnt[j];
  }
}

int find_centroid(int i, int p, int sum) {
  for (auto &j : adj[i]) {
    if (j == p || rem[j]) continue;
    if (cnt[j] > sum / 2) return find_centroid(j, i, sum);
  }
  return i;
}

int init_centroid(int i, int p) {
  dfs(i, -1);
  int t = find_centroid(i, -1, cnt[i]);
  par_centroid[t] = p;
  rem[t] = 1;
  for (auto &j : adj[t]) {
    if (!rem[j]) init_centroid(j, t);
  }
}

void vis(int i, int p) {
  for (auto &j : adj[i]) {
    if (j == p) continue;
    par[j][0] = i;
    dep[j] = dep[i] + 1;
    vis(j, i);
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
  memset(best, 0x3f, sizeof(best));
  init_centroid(1, -1);
  dep[1] = 1;
  vis(1, -1);
  for (int j = 1; j <= 20; j++)
  for (int i = 1; i <= n; i++) {
    par[i][j] = par[par[i][j - 1]][j - 1];
  }
  int p = 1;
  while (p != -1) {
    best[p] = dist(p, 1);
    p = par_centroid[p];
  }
  while (q--) {
    int t, x;
    cin >> t >> x;
    if (t == 1) {
      int p = x;
      while (p != -1) {
        best[p] = min(best[p], dist(p, x));
        p = par_centroid[p];
      }
    }
    else {
      int p = x, ans = 0x3f3f3f3f;
      while (p != -1) {
        ans = min(ans, best[p] + dist(p, x));
        p = par_centroid[p];
      }
      cout << ans << '\n';
    }
  }
}
