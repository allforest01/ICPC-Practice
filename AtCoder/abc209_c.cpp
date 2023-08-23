#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 1e9 + 7;

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<int> c(n);
  for (auto &i : c) {
    cin >> i;
  }
  sort(c.begin(), c.end());
  int ans = 1;
  for (int i = 0; i < n; i++) {
    (ans *= max(0ll, c[i] - i)) %= MOD;
  }
  cout << ans << '\n';
}
