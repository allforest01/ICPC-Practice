#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  for (int i = 0; i * 3 <= n; i++) {
    if ((n - i * 3) % 5 == 0) {
      cout << i + (n - i * 3) / 5 << '\n';
      return 0;
    }
  }
  cout << -1 << '\n';
}
