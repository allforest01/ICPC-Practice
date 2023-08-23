#include <bits/stdc++.h>
using namespace std;

long long lcm(long long a, long long b) {
  long long g = __gcd(a, b);
  return a / g * b;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  long long ans = 1;
  for (int i = 2; i <= n; i++) {
    ans = lcm(ans, i);
  }
  cout << ans + 1 << '\n';
}
