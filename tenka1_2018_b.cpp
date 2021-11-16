#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int a, b, k;
  cin >> a >> b >> k;
  bool taka = 1;
  while (k --> 0) {
    if (taka) {
      if (a % 2) a--;
      b += a / 2;
      a /= 2;
    }
    else {
      if (b % 2) b--;
      a += b / 2;
      b /= 2;
    }
    taka = !taka;
  }
  cout << a << ' ' << b << '\n';
}
