#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("pails.in" , "r", stdin );
  freopen("pails.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  int x, y, m;
  cin >> x >> y >> m;
  int ans = 0;
  for (int i = 0; i <= m / x; i++) {
    ans = max(ans, m - (m - x * i) % y);
  }
  cout << ans << '\n';
}
