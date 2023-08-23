#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll comb(ll n, ll k) {
  if (n < k) return 0;
  ll ret = 1;
  k = min(k, n - k);
  for (int i = 1; i <= k; i++) {
    ret *= n - k + i;
    ret /= i;
  }
  return ret;
}

void Main() {
  int n, q; cin >> n >> q;
  vector<int> odd(n + 1), even(n + 1);
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    if (x % 2) odd[i]++;
    else even[i]++;
    odd[i]  +=  odd[i - 1];
    even[i] += even[i - 1];
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    int o = odd[r] - odd[l - 1], e = even[r] - even[l - 1];
    ll ans = comb(e, 3) + comb(o, 2) * e;
    cout << ans << '\n';
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
