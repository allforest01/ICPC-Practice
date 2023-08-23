#include <bits/stdc++.h>
using namespace std;

int cnt(int n) {
  int ans = 0;
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      ans++;
      if (i * i != n) ans++;
    }
  }
  return ans;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  int ans = 0;
  for (int j = 1; j <= n; j++) {
    for (int i = 1; i * i <= j; i++) {
      if (j % i == 0) {
        ans += cnt(i);
        if (i * i != j) ans += cnt(j / i);
      }
    }
  }
  cout << ans << '\n';
}
