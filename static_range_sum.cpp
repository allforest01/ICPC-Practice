#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, q;
  cin >> n >> q;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (i > 0) a[i] += a[i - 1];
  }
  while (q --> 0) {
    int l, r;
    cin >> l >> r;
    long long ans = a[r - 1];
    if (l > 0) ans -= a[l - 1];
    cout << ans << '\n';
  }
}
