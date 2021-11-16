#include <bits/stdc++.h>
using namespace std;

#define Bit(x, k) (((x) >> (k)) & 1)

void Main() {
  int n; cin >> n;
  vector<int> a(n), b(n);
  for (auto &i : a) cin >> i;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < 30; j++) {
      if (Bit(a[i - 1], j) && !Bit(a[i], j)) {
        b[i] ^= (1 << j);
      }
    }
    a[i] ^= b[i];
  }
  for (auto &i : b) {
    cout << i << ' ';
  }
  cout << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
