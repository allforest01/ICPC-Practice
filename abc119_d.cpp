#include <bits/stdc++.h>
using namespace std;

long long dist(long long a, long long b) {
  return abs(a - b);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m, q;
  cin >> n >> m >> q;
  vector<long long> a(n + 2), b(m + 2);
  a[0] = b[0] = -30000000000;
  a[n + 1] = b[m + 1] = 30000000000;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
  }
  while (q--) {
    long long x; cin >> x;
    auto ia = lower_bound(a.begin(), a.end(), x);
    auto ib = lower_bound(b.begin(), b.end(), x);
    vector<long long> va = {*ia, *prev(ia)};
    vector<long long> vb = {*ib, *prev(ib)};
    long long ans = LLONG_MAX;
    for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++) {
      ans = min(ans, dist(x, va[i]) + dist(va[i], vb[j]));
      ans = min(ans, dist(x, vb[j]) + dist(vb[j], va[i]));
    }
    cout << ans << '\n';
  }
}
