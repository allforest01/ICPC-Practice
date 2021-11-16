#include <bits/stdc++.h>
using namespace std;

int ans(int n) {
  if (n == 3) return 0;
  if (n == 4) return 1;
  return 2 + ans((n + 1) / 2);
}

int main() {
  int n; cin >> n;
  for (int i = 3; i <= n; i++) {
    cout << i << ' ';
  }
  cout << '\n';
  for (int i = 3; i <= n; i++) {
    cout << ans(i) << ' ';
  }
  cout << '\n';
}