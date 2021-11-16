#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int s, t;
  cin >> s >> t;
  int ans = 0;
  for (int i = 0; i <= s; i++)
  for (int j = 0; j <= s; j++)
  for (int k = 0; k <= s; k++) {
    if (i + j + k <= s && i * j * k <= t) {
      ans++;
      // cout << i << ' ' << j << ' ' << k << '\n';
    }
  }
  cout << ans << '\n';
}
