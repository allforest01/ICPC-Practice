#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

vector<int> adj[N];

int ans = 0;

void dfs(int i, int p) {
  int k = adj[i].size() - (p != 0);
  if (k == 0) return;
  int t = 1, c = 0;
  while (t <= k) t *= 2, c++;
  ans += c + k;
  for (auto &j : adj[i]) {
    if (j != p) dfs(j, i);
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1, 0);
  cout << ans << '\n';
}
