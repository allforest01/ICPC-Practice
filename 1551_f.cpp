#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 105;
const int MOD = 1e9 + 7;

vector<int> adj[N];

void dfs(int i, int p, int l, vector<int> &c) {
  c[l]++;
  for (auto &j : adj[i]) {
    if (j != p) dfs(j, i, l + 1, c);
  }
}

void Main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    adj[i].clear();
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  if (m == 2) {
    cout << (n * (n - 1) / 2) % MOD << '\n';
    return;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    vector<vector<int>> cnt(1);
    for (auto &j : adj[i]) {
      vector<int> c(n);
      dfs(j, i, 1, c);
      cnt.push_back(c);
    }
    int si = adj[i].size();
    for (int k = 1; k <= n - 1; k++) {
      vector<vector<int>> dp(si + 1, vector<int>(m + 1));
      dp[0][0] = 1;
      for (int j = 1; j <= si; j++) {
        for (int l = 0; l <= m; l++) {
          dp[j][l] = dp[j - 1][l];
          if (l) {
            dp[j][l] += (dp[j - 1][l - 1] * cnt[j][k]) % MOD;
            dp[j][l] %= MOD;
          }
        }
      }
      ans += dp[si][m];
      ans %= MOD;
    }
  }
  cout << ans << '\n';
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
