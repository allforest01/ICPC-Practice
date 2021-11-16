#include <bits/stdc++.h>
using namespace std;

void chmax(int &a, int b) {
  if (a < b) a = b;
}

struct Bit {
  int n; vector<int> bit;
  Bit(int n): n(n), bit(n + 1) {}
  void update(int i, int v) {
    for (; i <= n; i += i & -i) {
      chmax(bit[i], v);
    }
  }
  int get(int i) {
    int v = 0;
    for (; i; i -= i & -i) {
      chmax(v, bit[i]);
    }
    return v;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<array<int,2>> a(n);
  for (auto &i : a) {
    cin >> i[0] >> i[1];
    i[0]++;
    i[1]++;
  }
  sort(a.begin(), a.end(),
    [](array<int,2> &a, array<int,2> &b)->bool {
      if (a[1] == b[1]) return a[0] < b[0];
      return a[1] < b[1];
    }
  );
  Bit bit(30001);
  int ans = 0;
  for (auto &i : a) {
    int t = bit.get(i[0]) + (i[1] - i[0]);
    bit.update(i[1], t);
    ans = max(ans, t);
  }
  cout << ans << '\n';
}
