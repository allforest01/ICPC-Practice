#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  ll a1, a2, a3;
  cin >> a1 >> a2 >> a3;
  ll l = 2 * a2, r = a1 + a3;
  if (l > r) {
    cout << l - r << '\n';
  }
  else {
    if ((r - l) % 2 == 0) {
      cout << (r - l) / 2 << '\n';
    }
    else {
      cout << (r - l + 1) / 2 + 1 << '\n';
    }
  }
}
