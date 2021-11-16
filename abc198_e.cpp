#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int color[N], good[N];
vector<int> adj[N];
multiset<int> ms;

void dfs(int i, int p) {
  if (!ms.count(color[i])) {
    good[i] = 1;
  }
  ms.insert(color[i]);
  for (auto &j : adj[i]) {
    if (j != p) dfs(j, i);
  }
  ms.erase(ms.find(color[i]));
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> color[i];
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1, 0);
  for (int i = 1; i <= n; i++) {
    if (good[i]) cout << i << '\n';
  }
}
