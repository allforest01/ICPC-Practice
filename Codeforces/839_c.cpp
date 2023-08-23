#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

vector<int> adj[N];

long double dfs(int i, int p) {
  long double ret = 0;
  for (auto &j : adj[i]) {
    if (j == p) continue;
    ret += dfs(j, i) + 1;
  }
  return ret ? ret / (adj[i].size() - (p != 0)) : 0;
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
  cout << setprecision(15) << fixed << dfs(1, 0) << '\n';
}
