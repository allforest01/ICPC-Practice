#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define all(x) (x).begin(),(x).end()

const int N = 1e5 + 5;

int n; ll k;
ll a[N], s[N];
int s_comp[N];
vector<ll> comp;

struct FW {
  int n; vector<int> bit;
  FW(int n): n(n), bit(n + 1) {}
  void update(int i, int v) {
    for (; i <= n; i += i & -i) {
      bit[i] += v;
    }
  }
  int get(int i) {
    int v = 0;
    for (; i; i -= i & -i) {
      v += bit[i];
    }
    return v;
  }
};

ll count(ll m) {
  // sumi - sumj >= m
  // sumi - m >= sumj
  ll ret = 0;
  FW fw(comp.size());
  fw.update(s_comp[0], 1);
  for (int i = 1; i <= n; i++) {
    ll t = s[i] - m;
    ll t_comp = upper_bound(all(comp), t) - comp.begin();
    if (t_comp != 0) ret += fw.get(t_comp);
    fw.update(s_comp[i], 1);
  }
  return ret;
}

int main() {
  cin >> n >> k;
  comp.push_back(0);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    s[i] = a[i] + s[i - 1];
    comp.push_back(s[i]);
  }
  sort(all(comp));
  comp.resize(unique(all(comp)) - comp.begin());
  for (int i = 0; i <= n; i++) {
    s_comp[i] = lower_bound(all(comp), s[i]) - comp.begin() + 1;
  }
  ll l = -1e14, r = 1e14, ans;
  while (l <= r) {
    ll m = (l + r) / 2;
    // cerr << m << ' ' << count(m) << '\n';
    if (count(m) >= k) {
      ans = m;
      l = m + 1;
    }
    else r = m - 1;
  }
  cout << ans << '\n';
}