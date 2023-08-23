#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 100005;
const int MOD = 1e9 + 7;

#define stack def_stack
#define all(x) (x).begin(),(x).end()

vector<int> adj[N], stack, sqz[N];
int tin[N], low[N], timer = 0;
int ssc[N], ssc_n = 0;
int par[N][20], dep[N], cnt[N];

void chmin(int &a, int b) {
  if (a > b) a = b;
}

void dfs(int i, int p) {
  tin[i] = low[i] = ++timer;
  stack.push_back(i);
  for (auto &j : adj[i]) {
    if (!tin[j]) {
      dfs(j, i);
      chmin(low[i], low[j]);
    }
    else if (j != p && tin[j] < tin[i]) {
      low[i] = low[j];
    }
  }
  if (tin[i] == low[i]) {
    ssc_n++;
    int c = 0;
    while (true) {
      int t = stack.back(); stack.pop_back();
      ssc[t] = ssc_n;
      c++;
      if (t == i) break;
    }
    if (c > 1) cnt[ssc_n] = 1;
  }
}

void vst(int i, int p) {
  for (auto &j : sqz[i]) {
    if (j != p) {
      par[j][0] = i;
      dep[j] = dep[i] + 1;
      cnt[j] += cnt[i];
      vst(j, i);
    }
  }
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

int modpow(int a, int b) {
  if (b == 0) return 1;
  int t = modpow(a, b / 2);
  t = (t * t) % MOD;
  if (b % 2) return (t * a) % MOD;
  return t;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1, -1);
  for (int i = 1; i <= n; i++) {
    for (auto &j : adj[i]) {
      if (ssc[i] != ssc[j]) {
        sqz[ssc[i]].push_back(ssc[j]);
      }
    }
  }
  for (int i = 1; i <= ssc_n; i++) {
    sort(all(sqz[i]));
    sqz[i].resize(unique(all(sqz[i])) - sqz[i].begin());
  }
  dep[1] = 1;
  vst(1, -1);
  for (int j = 1; j < 20; j++) {
    for (int i = 1; i <= n; i++) {
      par[i][j] = par[par[i][j - 1]][j - 1];
    }
  }
  int q; cin >> q;
  while (q--) {
    int u, v;
    cin >> u >> v;
    u = ssc[u]; v = ssc[v];
    int l = lca(u, v);
    int ans = cnt[u] + cnt[v] - cnt[l] - cnt[par[l][0]];
    cout << modpow(2, ans) << '\n';
  }
}
