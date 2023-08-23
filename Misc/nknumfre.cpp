#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int a, b, ans = 0;
  cin >> a >> b;
  for (int i = a; i <= b; i++) {
    int t = i, j = 0;
    while (t) {
      j = j * 10 + t % 10;
      t /= 10;
    }
    if (__gcd(i, j) == 1) {
      ans++;
    }
  }
  cout << ans << '\n';
}
