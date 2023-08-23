#include <bits/stdc++.h>
using namespace std;

int div_sum(int n) {
  int ret = 0;
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      ret += i;
      if (i * i != n) ret += n / i;
    }
  }
  return ret;
}

int gcd(int a, int b) {
  if (a % b == 0) return b;
  else return gcd(b, a % b);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int a, b;
  cin >> a >> b;
  int da = div_sum(a), db = div_sum(b);
  int ga = gcd(a, da), gb = gcd(b, db);
  a /= ga; da /= ga; b /= gb; db /= gb;
  if (a == b && da == db) {
    cout << da << '\n' << a << '\n';
  }
  else {
    cout << -1 << '\n';
  }
}
