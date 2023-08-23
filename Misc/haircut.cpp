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
  void update(int l, int r, int v) {
    update(l, v);
    update(r + 1, -v);
  }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  freopen("haircut.in" , "r", stdin );
  freopen("haircut.out", "w", stdout);
  int n; cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i]; a[i]++;
  }
  int ans = 0;
  vector<int> res(n);
  Bit bit1(n + 2), bit2(n + 2);
  for (int i = 1; i <= n; i++) {
    int t = bit1.get(a[i]);
    ans += t;
    bit1.update(1, a[i] - 1, 1);
    bit2.update(1, a[i], t);
  }
  for (int i = 1; i <= n; i++) {
    cout << ans - bit2.get(i) << '\n';
  }
}
