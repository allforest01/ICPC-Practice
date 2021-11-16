#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  long long ans = 0;
  vector<array<int,2>> cnt(31);
  for (auto &i : a) {
    for (int j = 0; j < 31; j++) {
      int t = (i >> j) & 1;
      ans += (1ll << j) * cnt[j][!t];
      cnt[j][t]++;
    }
  }
  cout << ans << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) solve();
}
