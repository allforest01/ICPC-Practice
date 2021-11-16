#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<int> a(n + 1), ma(n + 1), sum_a(n + 1), sum_sum_a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    ma[i] = max(a[i], ma[i - 1]);
    sum_a[i]  =  a[i] +  sum_a[i - 1];
    sum_sum_a[i] = sum_a[i] + sum_sum_a[i - 1];
  }
  for (int i = 1; i <= n; i++) {
    int ans = sum_a[i] + sum_sum_a[i - 1] + ma[i] * i;
    // cout << sum_a[i] << ' ' << sum_sum_a[i - 1] << ' ' << ma[i] * i << '\n';
    cout << ans << '\n';
  }
}
