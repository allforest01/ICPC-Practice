#include <bits/stdc++.h>
using namespace std;

const int N = 2005;

vector<int> adj[N];
int vst[N], ans = 0;

void dfs(int i) {
  if (vst[i]) return;
  vst[i] = 1;
  ans++;
  for (auto &j : adj[i]) {
    dfs(j);
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) vst[j] = 0;
    dfs(i);
  }
  cout << ans << '\n';
}
