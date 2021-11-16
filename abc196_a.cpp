#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int ans = INT_MIN;
  for (int i = a; i <= b; i++)
  for (int j = c; j <= d; j++) {
    ans = max(ans, i - j);
  }
  cout << ans << '\n';
}
