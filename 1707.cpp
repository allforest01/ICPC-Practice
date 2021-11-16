#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  vector<int> bfs(n + 1), dfs(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> bfs[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> dfs[i];
  }
  int p = 2, last = 1;
  vector<int> par(n + 1, 1), seen(n + 1);
  cout << n - 1 << '\n';
  for (int i = 2; i <= n; i++) {
    if (!seen[dfs[i]]) {
      while (p <= n && bfs[p] != dfs[i]) {
        if (!seen[bfs[p]]) {
          cout << par[last] << ' ' << bfs[p] << '\n';
          par[bfs[p]] = par[last];
          seen[bfs[p]] = 1;
        }
        p++;
      }
      cout << last << ' ' << dfs[i] << '\n';
      par[dfs[i]] = last;
      seen[dfs[i]] = 1;
    }
    last = dfs[i];
  }
}
