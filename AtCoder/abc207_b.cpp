#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  long long a, b, c, d;
  cin >> a >> b >> c >> d;
  if (d * c - b <= 0) {
    cout << -1 << '\n';
    return 0;
  }
  cout << setprecision(0) << fixed << ceil((double) a / (d * c - b)) << '\n';
}
