#include <bits/stdc++.h>
using namespace std;

double sum(double n) {
  return n * (n + 1) / 2;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  double n, m, d;
  cin >> n >> m >> d;
  double ans = (d > 0 ? 2 : 1) * (n - d) * (m - 1) / (n * n);
  cout << setprecision(10) << fixed << ans << '\n';
}
