#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 100005;

vector<int> adj[N];
int val[N][5], dp[N][5];

void dfs(int i, int p) {
  for (auto &j : adj[i]) {
    if (j != p) dfs(j, i);
  }
  for (int k = 0; k <= 1; k++) {
    for (auto &j : adj[i]) {
      if (j == p) continue;
      dp[i][k] += max(dp[j][0] + abs(val[i][k] - val[j][0]),
                      dp[j][1] + abs(val[i][k] - val[j][1]));
    }
  }
}

void Main() {
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    adj[i].clear();
    val[i][0] = val[i][1] = dp[i][0] = dp[i][1] = 0;
  }
  for (int i = 1; i <= n; i++) {
    cin >> val[i][0] >> val[i][1];
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1, -1);
  cout << max(dp[1][0], dp[1][1]) << '\n';
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
