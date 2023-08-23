#include <bits/stdc++.h>
using namespace std;

struct BIT {
  int n; vector<int> bit;
  BIT(int n): n(n) {
    bit.resize(n + 1);
  }
  void update(int i, int v) {
    for (; i <= n; i += i & -i) {
      bit[i] ^= v;
    }
  }
  int get(int i) {
    int v = 0;
    for (; i; i -= i & -i) {
      v ^= bit[i];
    }
    return v;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, q;
  cin >> n >> q;
  BIT bit(n);
  for (int i = 1; i <= n; i++) {
    int v; cin >> v;
    bit.update(i, v);
  }
  for (int i = 1; i <= q; i++) {
    int t, x, y;
    cin >> t >> x >> y;
    if (t == 1) {
      bit.update(x, y);
    }
    else {
      cout << (bit.get(y) ^ bit.get(x - 1)) << '\n';
    }
  }
}
