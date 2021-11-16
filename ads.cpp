#include <bits/stdc++.h>
using namespace std;

const int N = 2005;

vector<int> adj[N];
int vst[N], dep[N], ans = 0;

void dfs(int i, int p) {
  vst[i] = 1;
  for (auto &j : adj[i]) {
    if (j == p) continue;
    if (vst[j]) {
      if (dep[j] < dep[i]) ans++;
    }
    else {
      dep[j] = dep[i] + 1;
      dfs(j, i);
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    if (!vst[i]) dfs(i, -1);
  }
  cout << ans << '\n';
}