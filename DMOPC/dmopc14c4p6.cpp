#include <bits/stdc++.h>
using namespace std;

const int N = 500005;

int n;
vector<int> adj[N];

void chmax(int &a, int b) {
  if (a < b) a = b;
}

namespace sub2 {

  int dfs(int i, int p) {
    int ret = 0;
    for (auto &j : adj[i]) {
      if (j != p) chmax(ret, dfs(j, i));
    }
    return ret + 1;
  }

  void Main() {
    for (int i = 1; i <= n; i++) {
      cout << dfs(i, 0) << '\n';
    }
  }

}

namespace sub3 {

  int dp[N];

  void dfs1(int i, int p) {
    dp[i] = 1;
    for (auto &j : adj[i]) {
      if (j == p) continue;
      dfs1(j, i);
      chmax(dp[i], dp[j] + 1);
    }
  }

  void dfs2(int i, int p, int s) {
    chmax(dp[i], s);
    int k = adj[i].size();
    vector<int> l(k), r(k);
    for (int t = 0; t < k; t++) {
      int j = adj[i][t];
      if (j != p) l[t] = dp[j] + 1;
      if (t > 0) chmax(l[t], l[t - 1]);
    }
    for (int t = k - 1; t >= 0; t--) {
      int j = adj[i][t];
      if (j != p) r[t] = dp[j] + 1;
      if (t < k - 1) chmax(r[t], r[t + 1]);
    }
    for (int t = 0; t < k; t++) {
      int j = adj[i][t];
      if (j == p) continue;
      int d = s;
      if (t > 0) chmax(d, l[t - 1]);
      if (t < k - 1) chmax(d, r[t + 1]);
      dfs2(j, i, d + 1);
    }
  }

  void Main() {
    dfs1(1, 0);
    dfs2(1, 0, 1);
    for (int i = 1; i <= n; i++) {
      cout << dp[i] << '\n';
    }
  }

}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  if (n <= 7000) sub2::Main();
  else sub3::Main();
}
