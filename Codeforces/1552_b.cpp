#include <bits/stdc++.h>
using namespace std;

#define ar array

void chmin(int &a, int b) {
  if (a > b) a = b;
}

struct Bit {
  int n; vector<int> bit;
  Bit(int n): n(n), bit(n + 1, INT_MAX) {}
  void update(int i, int v) {
    for (; i <= n; i += i & -i) {
      chmin(bit[i], v);
    }
  }
  int get(int i) {
    int v = INT_MAX;
    for (; i; i -= i & -i) {
      chmin(v, bit[i]);
    }
    return v;
  }
};

void Main() {
  int n; cin >> n;
  vector<array<int,6>> a(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 5; j++) {
      cin >> a[i][j];
    }
    a[i][5] = i;
  }
  vector<int> res(n);
  for (int i = 0; i + 2 < 5; i++)
  for (int j = i + 1; j + 1 < 5; j++)
  for (int k = j + 1; k < 5; k++) {
    sort(a.begin(), a.end(), [&](ar<int,6> &a, ar<int,6> &b) {
      return a[i] < b[i];
    });
    Bit bit(50000);
    for (int t = 0; t < n; t++) {
      int g = bit.get(a[t][j]);
      if (g < a[t][k]) res[a[t][5]] = 1;
      bit.update(a[t][j] + 1, a[t][k]);
    }
  }
  for (int i = 0; i < (int) res.size(); i++) {
    if (!res[i]) {
      cout << i + 1 << '\n';
      return;
    }
  }
  cout << -1 << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
