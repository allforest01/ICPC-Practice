#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("promote.in" , "r", stdin );
  freopen("promote.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  int a[4], b[4], res[4]{};
  for (int i = 0; i < 4; i++) {
    cin >> a[i] >> b[i];
  }
  for (int i = 3; i >= 1; i--) {
    res[i] = b[i] - a[i];
    a[i - 1] -= res[i];
  }
  for (int i = 1; i <= 3; i++) {
    cout << res[i] << '\n';
  }
}
