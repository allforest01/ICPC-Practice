#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int a, b, c;
  cin >> a >> b >> c;
  if (a == b) {
    cout << c << '\n';
    return 0;
  }
  if (a == c) {
    cout << b << '\n';
    return 0;
  }
  if (b == c) {
    cout << a << '\n';
    return 0;
  }
  cout << 0 << '\n';
}
