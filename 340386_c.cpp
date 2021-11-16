#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 200005;

int a[N], sum[N];

struct Bit {
  int n; vector<int> bit;
  Bit(int n): n(n), bit(n + 1) {}
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

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, t;
  cin >> n >> t;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum[i] = sum[i - 1] + a[i];
  }
  set<int> s;
  s.insert(0);
  for (int i = 1; i <= n; i++) {
    s.insert(sum[i]);
    s.insert(sum[i] - t);
  }
  vector<int> v(s.begin(), s.end());
  Bit bit(v.size());
  int zr = lower_bound(v.begin(), v.end(), 0) - v.begin() + 1;
  bit.update(zr, 1);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int f = lower_bound(v.begin(), v.end(), sum[i]) - v.begin() + 1;
    int s = lower_bound(v.begin(), v.end(), sum[i] - t) - v.begin() + 1;
    ans += i - bit.get(s);
    bit.update(f, 1);
  }
  cout << ans << '\n';
}
