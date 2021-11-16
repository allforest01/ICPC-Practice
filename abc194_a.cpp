#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int a, b;
  cin >> a >> b;
  a += b;
  int ans = -1;
  if (a >= 15 && b >= 8) ans = 1;
  else if (a >= 10 && b >= 3) ans = 2;
  else if (a >= 3) ans = 3;
  else ans = 4;
  cout << ans << '\n';
}
