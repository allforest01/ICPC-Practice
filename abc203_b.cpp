#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  int ans = 0;
  for (int i = 1; i <= n; i++)
  for (int j = 1; j <= k; j++) {
    ans += i * 100 + j;
  }
  cout << ans << '\n';
}
