#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<int> mark((int)(1e5) + 1);
  for (int i = 0; i < n; i++) {
    int t; cin >> t;
    for (int j = 2; j * j <= t; j++) {
      if (t % j == 0) {
        while (t % j == 0) t /= j;
        mark[j] = 1;
      }
    }
    if (t > 1) mark[t] = 1;
  }
  for (int i = 1; i <= m; i++) {
    if (!mark[i]) continue;
    for (int j = i * 2; j <= m; j += i) {
      mark[j] = 1;
    }
  }
  vector<int> res;
  for (int i = 1; i <= m; i++) {
    if (!mark[i]) {
      res.push_back(i);
    }
  }
  cout << res.size() << '\n';
  for (auto &i : res) cout << i << '\n';
}
