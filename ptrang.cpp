#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, l;
  cin >> n >> l;
  vector<int> a(n + 1), s(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    s[i] = a[i] + s[i - 1];
  }
  vector<int> dp(n + 1);
  for (int i = 1; i <= n; i++) {
    dp[i] = 2e9;
    for (int j = i; j >= 1; j--) {
      if (s[i] - s[j - 1] > l) break;
      dp[i] = min(dp[i], max(l - (s[i] - s[j - 1]), dp[j - 1]));
    }
  }
  cout << dp[n] << '\n';
}