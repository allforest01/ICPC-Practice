#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; double D, H;
  cin >> n >> D >> H;
  double ans = 0;
  for (int i = 0; i < n; i++) {
    double d, h;
    cin >> d >> h;
    ans = max(ans, (h * D - H * d) / (D - d));
  }
  cout << setprecision(10) << fixed << ans << '\n';
}
