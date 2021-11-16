#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1005;
const int M = 105;
const int MOD = 998244353;

vector<int> adj[N];
int dep[N], par[N][25];
int a[M], cnt[N], dp[N][N * M];
vector<int> vec(1);

void dfs(int i, int p) {  
  for (auto &j : adj[i]) {
    if (j == p) continue;
    dep[j] = dep[i] + 1;
    par[j][0] = i;
    dfs(j, i);
  }
}

void vst(int i, int p) {
  for (auto &j : adj[i]) {
    if (j == p) continue;
    vst(j, i);
    cnt[i] += cnt[j];
  }
  vec.push_back(cnt[i]);
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

signed main() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 1; i <= m; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n - 1; i++) {
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
  for (int i = 1; i <= m - 1; i++) {
    cnt[a[i    ]] += 1;
    cnt[a[i + 1]] += 1;
    cnt[lca(a[i], a[i + 1])] -= 2;
  }
  vst(1, -1);
  int sum = 0;
  for (int i = 1; i <= n - 1; i++) {
    sum += vec[i];
  }
  dp[0][0] = 1;
  for (int i = 1; i <= n - 1; i++)
  for (int j = 0; j <= sum; j++) {
    dp[i][j] = dp[i - 1][j];
    if (j >= vec[i]) (dp[i][j] += dp[i - 1][j - vec[i]]) %= MOD;
  }
  cout << dp[n - 1][(sum + abs(k)) / 2] << '\n';
  for (int i = 0; i <= sum; i++) {
    cout << dp[n - 1][i] << ' ';
  }
  cout << '\n';
}