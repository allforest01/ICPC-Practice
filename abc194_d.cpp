#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  double ans = 0;
  for (int i = 1; i < n; i++) {
    ans += (double)(n) / (n - i);
  }
  cout << setprecision(10) << fixed << ans << '\n';
}
