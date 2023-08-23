#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int k, d;
  cin >> k >> d;
  vector<bool> a(10);
  for (int i = 0; i < d; i++) {
    int x; cin >> x;
    a[x] = true;
  }
  bool flag = false;
  for (int i = 1; i <= 9; i++) {
    if (a[i]) {
      flag = true;
      cout << i;
      for (int j = 1; j <= k - 2; j++) {
        cout << (a[0] ? 0 : i);
      }
      if (k >= 2) cout << i;
      cout << '\n';
      break;
    }
  }
  if (!flag) cout << "-1" << '\n';
}
