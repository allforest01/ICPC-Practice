#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, x, s = 0;
  cin >> n >> x;
  x *= 100;
  for (int i = 1; i <= n; i++) {
    int v, p;
    cin >> v >> p;
    s += v * p;
    if (s > x) {
      cout << i << '\n';
      return 0;
    }
  }
  cout << -1 << '\n';
}
