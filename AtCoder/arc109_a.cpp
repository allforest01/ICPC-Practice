#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int a, b, x, y;
  cin >> a >> b >> x >> y;
  int ans = x;
  if (b >= a) {
    ans += (b - a) * min(x * 2, y);
  }
  else {
    ans += (a - 1 - b) * min(x * 2, y);
  }
  cout << ans << '\n';
}
