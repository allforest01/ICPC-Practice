#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int m, d;
  cin >> m >> d;
  int ans = 0;
  for (int i = 4; i <= m; i++)
  for (int j = 2; j <= 9; j++)
  for (int k = 2; k <= 9; k++) {
    if (j * 10 + k <= d && j * k == i) {
      ans++;
    }
  }
  cout << ans << '\n';
}
