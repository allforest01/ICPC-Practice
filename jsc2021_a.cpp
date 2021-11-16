#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  long long x, y, z;
  cin >> x >> y >> z;
  long long lcm = x / __gcd(x, z) * z;
  long long ans = 0;
  for (int i = 0; i <= 1000000; i++) {
    if (i * (lcm / z) < y * (lcm / x)) {
      ans = i;
    }
  }
  cout << ans << '\n';
}
