#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

set<int> adj[N];
int vst[N], par[N];

void dfs(int i) {
  cout << i << ' ';
  vst[i] = 1;
  while (adj[i].size() && vst[*adj[i].begin()]) {
    adj[i].erase(adj[i].begin());
  }
  if (adj[i].size()) {
    int j = *adj[i].begin();
    adj[i].erase(adj[i].begin());
    par[j] = i;
    dfs(j);
  }
  else {
    if (i == 1) {
      cout << '\n';
      exit(0);
    }
    dfs(par[i]);
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].insert(v);
    adj[v].insert(u);
  }
  dfs(1);
}
