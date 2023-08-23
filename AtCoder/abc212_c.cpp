#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (auto &i : a) cin >> i;
  set<int> s;
  for (int i = 0; i < m; i++) {
    int x; cin >> x;
    s.insert(x);
  }
  int ans = INT_MAX;
  for (auto &i : a) {
    auto it = s.lower_bound(i);
    if (it != s.end()) ans = min(ans, *it - i);
    if (it != s.begin()) ans = min(ans, i - *prev(it));
  }
  cout << ans << '\n';
}
