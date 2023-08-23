#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, x;
  cin >> n >> x;
  for (int i = 1; i <= n; i++) {
    int t; cin >> t;
    if (i % 2 == 0 && t > 0) t--;
    x -= t;
  }
  if (x >= 0) cout << "Yes" << '\n';
  else cout << "No" << '\n';
}
