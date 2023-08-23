#include <bits/stdc++.h>
using namespace std;

void chmin(int &a, int b) {
  if (a > b) a = b;
}

int main() {
  freopen("teleport.in" , "r", stdin );
  freopen("teleport.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  int a, b, x, y;
  cin >> a >> b >> x >> y;
  int ans = abs(b - a);
  chmin(ans, abs(a - x) + abs(b - y));
  chmin(ans, abs(a - y) + abs(b - x));
  cout << ans << '\n';
}
