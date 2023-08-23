#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define sqr(x) ((x)*(x))

int m, n, q;

namespace sub1 {

  const int N = 1005;

  ll a[N];

  void Main() {
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    while (q--) {
      int t;
      cin >> t;
      if (t == 1) {
        int l, r; ll x;
        cin >> l >> r >> x;
        for (int i = l; i <= r; i++) {
          a[i] += x;
        }
      }
      else if (t == 2) {
        int l, r;
        cin >> l >> r;
        ll ans = 0;
        for (int i = l; i <= r; i++) {
          ans += sqr(a[i]);
          ans %= 2;
        }
        cout << ans << '\n';
      }
    }
  }

}

namespace sub2 {

  const int N = 100005;

  struct Bit {

    int n; vector<ll> bit;

    Bit(int n): n(n), bit(n + 1) {}

    void update(int i, ll v) {
      for (; i <= n; i += i & -i) {
        bit[i] += v;
      }
    }

    ll get(int i) {
      int v = 0;
      for (; i; i -= i & -i) {
        v += bit[i];
      }
      return v;
    }

  };

  void Main() {
    Bit bit(n);
    for (int i = 1; i <= n; i++) {
      int x; cin >> x;
      bit.update(i, x);
      bit.update(i + 1, -x);
    }
    while (q--) {
      int t;
      cin >> t;
      if (t == 1) {
        int l, r; ll x;
        cin >> l >> r >> x;
        bit.update(l, x);
        bit.update(r + 1, -x);
      }
      else if (t == 2) {
        int l, r;
        cin >> l >> r;
        ll ans = bit.get(r) - bit.get(l - 1);
        cout << ans << '\n';
      }
    }
  }

}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> m >> n >> q;
  /*if (m == 2 && n <= 1000 && q <= 1000) sub1::Main();
  else if (m == 2 && n <= 100000 && q <= 100000)*/ sub2::Main();
}
