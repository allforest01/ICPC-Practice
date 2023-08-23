#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll sum(ll l, ll r) {
  return (r - l + 1) * (r + l) / 2;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  freopen("race.in" , "r", stdin );
  freopen("race.out", "w", stdout);
  ll n; int k;
  cin >> n >> k;
  ll ma = -1;
  vector<ll> mem(1);
  for (ll i = 1; sum(1, i) <= n; i++) {
    ll l = i, r = n, ans = -1;
    while (l <= r) {
      ll m = (l + r) / 2;
      if (sum(1, m) + sum(i, m - 1) <= n) {
        ans = m;
        l = m + 1;
      }
      else r = m - 1;
    }
    ll s = sum(1, ans) + sum(i, ans - 1);
    mem.push_back(ans * 2 - i + (n - s + ans - 1) / ans);
  }
  while (k--) {
    ll x; cin >> x;
    if (x >= mem.size()) cout << mem.back() << '\n';
    else cout << mem[x] << '\n';
  }
}
