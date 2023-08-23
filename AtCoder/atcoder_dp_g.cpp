#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

vector<int> adj[N];
int inDeg[N], dp[N], vst[N];

void chmax(int &a, int b) {
  if (a < b) a = b;
}

void dfs(int i) {
  vst[i] = 1;
  for (auto &j : adj[i]) {
    chmax(dp[j], dp[i] + 1);
    inDeg[j]--;
    if (inDeg[j] == 0) dfs(j);
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    inDeg[v]++;
  }
  for (int i = 1; i <= n; i++) {
    if (inDeg[i] == 0 && !vst[i]) dfs(i);
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    chmax(ans, dp[i]);
  }
  cout << ans << '\n';
}