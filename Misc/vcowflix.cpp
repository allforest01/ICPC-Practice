#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int c, n;
  cin >> c >> n;
  vector<int> a(n);
  for (auto &i : a) cin >> i;
  int ans = 0;
  for (int mask = 0; mask < (1 << n); mask++) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
      if ((mask >> i) & 1) sum += a[i];
    }
    if (sum <= c) ans = max(ans, sum);
  }
  cout << ans << '\n';
}
