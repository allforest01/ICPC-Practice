#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

typedef long long ll;

struct FW {
  int n; vector<ll> bit;
  FW(int n): n(n), bit(n + 1) {}
  void update(int i, ll v) {
    for (; i <= n; i += i & -i) {
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
  ll get(int i, int j) {
    return get(j) - get(i - 1);
  }
};

int n, k; FW fw(N);

ll get_sum(ll l, ll r) {
  ll t = (l - 1) / n;
  l -= n * t;
  r -= n * t;
  if (r > n) {
    ll mid = (r - l + 1 - (n - l + 1) - r % n) / n;
    ll ret = fw.get(l, n) + fw.get(r % n) + fw.get(n) * mid;
    return ret;
  }
  return fw.get(l, r);
}

int next_pos(int p) {
  ll l = p + 1, r = p + (ll) n * k, ret = -1;
  while (l <= r) {
    ll m = (l + r) / 2;
    ll t = get_sum(p + 1, m);
    if (t >= k) {
      ret = m;
      r = m - 1;
    }
    else l = m + 1;
  }
  return (ret % n ? ret % n : n);
}

signed main() {
  cin >> n >> k;
  k++;
  for (int i = 1; i <= n; i++) {
    fw.update(i, 1);
  }
  int p = (k % n ? k % n : n);
  for (int i = 1; i <= n; i++) {
    cout << p << ' ';
    fw.update(p, -1);
    p = next_pos(p);
  }
  cout << '\n';
}
