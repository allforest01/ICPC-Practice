#include <bits/stdc++.h>
using namespace std;

#define int long long

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
  int n; cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int ans = 0;
  Bit cnt0(n), cnt1(n);
  for (int i = n; i >= 1; i--) {
    ans += cnt1.get(a[i]);
    cnt1.update(a[i] + 1, cnt0.get(a[i]));
    cnt0.update(a[i] + 1, 1);
  }
  cout << ans << '\n';
}
