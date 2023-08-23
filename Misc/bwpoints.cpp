#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  vector<array<int, 2>> a(n * 2);
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    a[i] = {x, 0};
  }
  for (int i = n; i < n * 2; i++) {
    int x; cin >> x;
    a[i] = {x, 1};
  }
  sort(a.begin(), a.end());
  vector<int> dp(n * 2);
  array<int,2> last = {-1, -1};
  for (int i = 0; i < n * 2; i++) {
    // int p = a[i][0];
    int t = a[i][1];
    if (last[t ^ 1] != -1) {
      dp[i] = 1;
      if (last[t ^ 1] > 0) dp[i] += dp[last[t ^ 1] - 1];
    }
    if (i > 0) dp[i] = max(dp[i], dp[i - 1]);
    last[t] = i;
  }
  cout << dp[n * 2 - 1] << '\n';
}