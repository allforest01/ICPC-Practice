#include <bits/stdc++.h>
using namespace std;

const int N = 105;

vector<int> adj[N];
int cnt[N];

void dfs(int i) {
  cnt[i]++;
  for (auto &j : adj[i]) dfs(j);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  freopen("factory.in" , "r", stdin );
  freopen("factory.out", "w", stdout);
  int n; cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
  }
  for (int i = 1; i <= n; i++) {
    dfs(i);
  }
  for (int i = 1; i <= n; i++) {
    if (cnt[i] == n) {
      cout << i << '\n';
      return 0;
    }
  }
  cout << -1 << '\n';
}
