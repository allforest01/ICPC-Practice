#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int x, y;
  cin >> x >> y;
  if (x == y) {
    cout << x << '\n';
    return 0;
  }
  cout << 3 - x - y << '\n';
}
