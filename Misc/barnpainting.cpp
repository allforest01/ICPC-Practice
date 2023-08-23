#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 100005;
const int MOD = 1e9 + 7;

vector<int> adj[N];
int col[N], dp[N][5];

void dfs(int i, int p) {
  for (auto &j : adj[i]) {
    if (j != p) dfs(j, i);
  }
  for (int k = 1; k <= 3; k++) {
    if (!col[i] || col[i] == k) {
      dp[i][k] = 1;
      for (auto &j : adj[i]) {
        if (j == p) continue;
        int t = 0;
        for (int l = 1; l <= 3; l++) {
          if (k == l) continue;
          (t += dp[j][l]) %= MOD;
        }
        (dp[i][k] *= t) %= MOD;
      }
    }
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  freopen("barnpainting.in" , "r", stdin );
  freopen("barnpainting.out", "w", stdout);
  int n, k;
  cin >> n >> k;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (int i = 0; i < k; i++) {
    int b, c;
    cin >> b >> c;
    col[b] = c;
  }
  dfs(1, -1);
  cout << (dp[1][1] + dp[1][2] + dp[1][3]) % MOD << '\n';
}
