#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())

struct str {
  long long val; int s, t;
  str() {}
  str(long long val, int s, int t): val(val), s(s), t(t) {}
  bool operator<(str &x) {
    return this->val < x.val;
  }
};

void chmin(long long &a, long long b) {
  if (a > b) a = b;
}

vector<str> gene(vector<long long> &a, vector<long long> &b) {
  vector<str> ret;
  for (int i = 0; i < sz(a); i++) {
    auto it = lower_bound(b.begin(), b.end(), a[i]);
    vector<str> tmp;
    if (it != b.end()) {
      tmp.push_back(str(abs(a[i] - *it), i, it - b.begin()));
    }
    if (it != b.begin()) {
      tmp.push_back(str(abs(a[i] - *prev(it)), i, prev(it) - b.begin()));
    }
    sort(tmp.begin(), tmp.end());
    if (sz(tmp)) ret.push_back(tmp[0]);
    else ret.push_back(str(1e16, -1, -1));
  }
  return ret;
}

void comp(vector<long long> &a, vector<long long> &b, vector<long long> &c) {
  vector<str> ab = gene(a, b), ca = gene(c, a), cb = gene(c, b);
  sort(ab.begin(), ab.end());
  long long ans = LLONG_MAX;
  chmin(ans, ab[0].val);
  // cout << "ca: ";
  /*long long mca = LLONG_MAX;
  for (auto &i : ca) {
    // cout << i.val << ' ';
    chmin(mca, i.val);
  }
  // cout << '\n';
  // cout << "cb: ";
  long long mcb = LLONG_MAX;
  for (auto &i : cb) {
    // cout << i.val << ' ';
    chmin(mcb, i.val);
  }
  // cout << '\n';
  cout << mca << '\n';
  cout << mcb << '\n';*/
  if (sz(ca) && sz(cb)) {
    vector<long long> l(sz(ca)), r(sz(ca));
    for (int i = 0; i < sz(ca); i++) {
      l[i] = ca[i].val;
      if (i > 0) chmin(l[i], l[i - 1]);
    }
    for (int i = sz(ca) - 1; i >= 0; i--) {
      r[i] = ca[i].val;
      if (i < sz(ca) - 1) chmin(r[i], r[i + 1]);
    }
    /*cout << "l : ";
    for (int i = 0; i < sz(ca); i++) {
      cout << l[i] << ' ';
    }
    cout << '\n';
    cout << "r : ";
    for (int i = 0; i < sz(ca); i++) {
      cout << r[i] << ' ';
    }
    cout << '\n';*/
    for (int i = 0; i < sz(cb); i++) {
      if (i > 0) chmin(ans, cb[i].val + l[i - 1]);
      if (i < sz(cb) - 1) chmin(ans, cb[i].val + r[i + 1]);
    }
  }
  cout << ans << '\n';
}

int main() {
  // freopen("in", "r", stdin);
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<vector<long long>> v(3);
  for (int i = 0; i < n * 2; i++) {
    long long x; char c;
    cin >> x >> c;
    if (c == 'R') v[0].push_back(x);
    if (c == 'G') v[1].push_back(x);
    if (c == 'B') v[2].push_back(x);
  }
  sort(v[0].begin(), v[0].end());
  sort(v[1].begin(), v[1].end());
  sort(v[2].begin(), v[2].end());
  if (sz(v[0]) % 2 == 0 && sz(v[1]) % 2 == 0 && sz(v[2]) % 2 == 0) {
    cout << 0 << '\n';
    return 0;
  }
  if (sz(v[0]) % 2 == 0) comp(v[1], v[2], v[0]);
  if (sz(v[1]) % 2 == 0) comp(v[0], v[2], v[1]);
  if (sz(v[2]) % 2 == 0) comp(v[0], v[1], v[2]);
}
