#include <bits/stdc++.h>
using namespace std;

int main() {
  long long a1, b1, a2, b2;
  cin >> a1 >> b1 >> a2 >> b2;
  if (a1 > b1) swap(a1, b1);
  if (a2 > b2) swap(a2, b2);
  long long g1 = __gcd(a1, b1);
  long long g2 = __gcd(a2, b2);
  a1 /= g1; b1 /= g1;
  a2 /= g2; b2 /= g2;
  if (a1 == a2 && b1 == b2) {
    cout << "YES" << '\n';
  }
  else cout << "NO" << '\n';
}
