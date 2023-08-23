#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  int ans = INT_MAX;
  for (int i = 0; i < n; i++) {
    int a, p, x;
    cin >> a >> p >> x;
    if (x > a) ans = min(ans, p);
  }
  if (ans == INT_MAX) ans = -1;
  cout << ans << '\n';
}
