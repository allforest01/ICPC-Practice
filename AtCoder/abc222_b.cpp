#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, p;
  cin >> n >> p;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    if (x < p) ans++;
  }
  cout << ans << '\n';
}