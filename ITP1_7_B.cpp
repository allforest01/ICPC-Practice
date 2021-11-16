#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, x;
  while (cin >> n >> x) {
    if (n == 0 && x == 0) return 0;
    int ans = 0;
    for (int i = 1; i + 2 <= n; i++)
    for (int j = i + 1; j + 1 <= n; j++)
    for (int k = j + 1; k <= n; k++) {
      if (i + j + k == x) ans++;
    }
    cout << ans << '\n';
  }
}
