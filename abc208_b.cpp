#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  vector<int> fact(11, 1);
  for (int i = 1; i <= 10; i++) {
    for (int j = 1; j <= i; j++) {
      fact[i] *= j;
    }
  }
  int n; cin >> n;
  int ans = 0;
  for (int i = 10; i >= 1; i--) {
    ans += n / fact[i];
    n %= fact[i];
  }
  cout << ans << '\n';
}
