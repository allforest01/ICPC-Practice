#include <bits/stdc++.h>
using namespace std;

void Main() {
  int x, y;
  cin >> x >> y;
  int s = x + y;
  if (s >= 6) {
    cout << 0 << '\n';
    return;
  }
  cout << fixed << setprecision(10) << (6 - s) / 6.0 << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
