#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int a, b, w;
  cin >> a >> b >> w;
  w *= 1000;
  int mi = INT_MAX, ma = INT_MIN;
  for (int i = 1; i <= 1000000; i++) {
    if (i * a <= w && w <= i * b) {
      mi = min(mi, i);
      ma = max(ma, i);
    }
  }
  if (mi == INT_MAX) {
    cout << "UNSATISFIABLE" << '\n';
    return 0;
  }
  cout << mi << ' ' << ma << '\n';
}
