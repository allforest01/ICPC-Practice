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

void Main() {
  int n; cin >> n;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  Bit bit(1e7);
  int ans = 0;
  for (int i = n - 1; i >= 0; i--) {
    ans += bit.get(a[i]);
    bit.update(a[i] + 1, 1);
  }
  cout << ans << '\n';
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}