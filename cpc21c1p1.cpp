#include <bits/stdc++.h>
using namespace std;

void Main() {
  long long a, b;
  cin >> a >> b;
  long long g = __gcd(a, b);
  a /= g; b /= g;
  int cnt2 = 0, cnt5 = 0;
  while (b % 2 == 0) {
    b /= 2;
    cnt2++;
  }
  while (b % 5 == 0) {
    b /= 5;
    cnt5++;
  }
  if (b == 1) cout << max(cnt2, cnt5) << '\n';
  else cout << -1 << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
