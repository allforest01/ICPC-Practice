#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int a, b, c;
  cin >> a >> b >> c;
  if (c % 2 == 0) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
  }
  if (a > b) cout << '>' << '\n';
  else if (a < b) cout << '<' << '\n';
  else cout << '=' << '\n';
}
