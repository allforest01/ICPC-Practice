#include <bits/stdc++.h>
using namespace std;

void Main() {
  long long a, b;
  cin >> a >> b;
  if (a == b) {
    cout << "0 0" << '\n';
    return;
  }
  if (a == 0 || b == 0) {
    cout << max(a, b) << " 0" << '\n';
    return;
  }
  long long d = abs(a - b);
  long long t = a / d;
  long long ans = min(a - d * t, d * (t + 1) - a);
  cout << d << ' ' << ans << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
