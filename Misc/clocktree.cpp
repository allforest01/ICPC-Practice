#include <bits/stdc++.h>
using namespace std;

const int N = 2505;

int n, a[N], flag = 0;
vector<int> adj[N];

void dfs(int i) {
  int cnt = 0;
  for (auto &j : adj[i]) {
    if (!dfs(j)) cnt++;
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    dfs(i);
    if (flag) ans++;
  }
  cout << ans << '\n';
}
