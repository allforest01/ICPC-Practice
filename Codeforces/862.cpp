#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 100005;

vector<int> adj[N];
int odd = 0, even = 0;

void dfs(int i, int p, int c) {
  if (c % 2) odd++; else even++;
  for (auto &j : adj[i]) {
    if (j != p) dfs(j, i, c ^ 1);
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1, 1, 1);
  cout << odd * even - (n - 1) << '\n';
}
