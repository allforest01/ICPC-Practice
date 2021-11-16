#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  int odd = 0, even = 0;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    if (x % 2) odd++;
    else even++;
  }
  int ans = 0;
  for (int i = 0; i <= odd; i += 2) {
    int o = odd - i, e = even + i / 2;
    if (e >= o) ans = max(ans, o * 2 + (e > o));
  }
  cout << ans << '\n';
}
