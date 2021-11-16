#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int x, y; char c;
  cin >> x >> c >> y;
  if (0 <= y && y <= 2) cout << x << "-" << '\n';
  else if (3 <= y && y <= 6) cout << x << '\n';
  else cout << x << "+" << '\n';
}
