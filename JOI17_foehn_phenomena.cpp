#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 200005;

int n, q; ll s, t;

// n <= 2000 && q <= 2000
namespace sub1 {
  ll alti[N], temp[N];

  void Main() {
    for (int i = 0; i <= n; i++) {
      cin >> alti[i];
    }
    while (q--) {
      int l, r; ll x;
      cin >> l >> r >> x;
      for (int i = l; i <= r; i++) {
        alti[i] += x;
      }
      for (int i = 1; i <= n; i++) {
        if (alti[i - 1] < alti[i]) {
          temp[i] = temp[i - 1] - s * (alti[i] - alti[i - 1]);
        }
        else {
          temp[i] = temp[i - 1] + t * (alti[i - 1] - alti[i]);
        }
      }
      cout << temp[n] << '\n';
    }
  }
}

// s == t
namespace sub2 {
  ll alti[N];

  void Main() {
    for (int i = 0; i <= n; i++) {
      cin >> alti[i];
    }
    while (q--) {
      int l, r; ll x;
      cin >> l >> r >> x;
      if (r == n) alti[n] += x;
      cout << alti[n] * (-t) << '\n';
    }
  }
}

struct Bit {
  vector<ll> bit;
  Bit(int n): bit(n + 1) {}
  void update(int i, ll v) {
    for (; i < (int) bit.size(); i += i & -i) {
      bit[i] += v;
    }
  }
  ll get(int i) {
    ll v = 0;
    for (; i; i -= i & -i) {
      v += bit[i];
    }
    return v;
  }
};

namespace sub3 {
  ll a[N], diff[N];

  void updDiff(Bit &alti, int p) {
    if (p > n) return;
    diff[p] = alti.get(p) - alti.get(p - 1);
  }

  void addAns(ll &ans, int p) {
    if (p > n) return;
    if (diff[p] > 0) ans -= s * diff[p];
    else ans += t * (-diff[p]);
  }

  void remAns(ll &ans, int p) {
    if (p > n) return;
    if (diff[p] > 0) ans += s * diff[p];
    else ans -= t * (-diff[p]);
  }

  void Main() {
    ll ans = 0;
    Bit alti(n + 1);
    for (int i = 0; i <= n; i++) {
      cin >> a[i];
      if (i > 0) {
        diff[i] = a[i] - a[i - 1];
        alti.update(i, diff[i]);
        if (diff[i] > 0) ans -= s * diff[i];
        else ans += t * (-diff[i]);
      }
    }
    while (q--) {
      int l, r; ll x;
      cin >> l >> r >> x;
      remAns(ans, l);
      remAns(ans, r + 1);
      alti.update(l, x);
      alti.update(r + 1, -x);
      updDiff(alti, l);
      updDiff(alti, r + 1);
      addAns(ans, l);
      addAns(ans, r + 1);
      cout << ans << '\n';
    }
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> q >> s >> t;
  if (n <= 2000 && q <= 2000) sub1::Main();
  else if (s == t) sub2::Main();
  else sub3::Main();
}
