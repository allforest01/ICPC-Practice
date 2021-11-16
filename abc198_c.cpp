#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-10;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  double r, x, y;
  cin >> r >> x >> y;
  double dist = sqrt(x * x + y * y);
  if (abs(dist - r) < EPS) cout << 1 << '\n';
  else cout << setprecision(0) << fixed << max(ceil(dist / r), 2.0) << '\n';
}
