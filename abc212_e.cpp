#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 5005;
const int MOD = 998244353;

int dp[N][N], ch[N][N];
vector<int> adj[N];

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    adj[i].push_back(i);
  }
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dp[1][0] = 1;
  for (int d = 1; d <= k; d++) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
      (sum += dp[i][d - 1]) %= MOD;
    }
    for (int i = 1; i <= n; i++) {
      dp[i][d] = sum;
      for (auto &j : adj[i]) {
        dp[i][d] -= dp[j][d - 1];
        dp[i][d] = (dp[i][d] % MOD + MOD) % MOD;
      }
    }
  }
  cout << dp[1][k] << '\n';
}
