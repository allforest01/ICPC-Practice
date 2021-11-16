#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int a[7], res[3];
  for (int i = 0; i < 7; i++) {
    cin >> a[i];
  }
  sort(a, a + 7);
  res[0] = a[6] - a[5];
  res[1] = a[6] - a[4];
  res[2] = a[6] - res[0] - res[1];
  cout << res[0] << ' ' << res[1] << ' ' << res[2] << '\n';
}
