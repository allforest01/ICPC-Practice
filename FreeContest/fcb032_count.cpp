#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int a[N], res[N];
vector<int> adj[N];
set<int> s[N];

void dfs(int i, int p) {
  for (auto &j : adj[i]) {
    if (j == p) continue;
    dfs(j, i);
    if (s[j].size() > s[i].size()) swap(s[i], s[j]);
    for (auto &k : s[j]) s[i].insert(k);
  }
  s[i].insert(a[i]);
  res[i] = s[i].size();
}

int main() {
  int n; cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  dfs(1, 1);
  for (int i = 1; i <= n; i++) {
    cout << res[i] << ' ';
  }
  cout << '\n';
}
