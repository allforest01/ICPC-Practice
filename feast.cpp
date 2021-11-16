#include <bits/stdc++.h>
using namespace std;

const int N = 5000005;

int dp[N];

void chmax(int &a, int b) {
  if (a < b) a = b;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  freopen("feast.in" , "r", stdin );
  freopen("feast.out", "w", stdout);
  int n, a, b;
  cin >> n >> a >> b;
  for (int i = 1; i <= n; i++) {
    dp[i] = dp[i - 1];
    if (i >= a) chmax(dp[i], dp[i - a] + a);
    if (i >= b) chmax(dp[i], dp[i - b] + b);
  }
  int ans = 0;
  for (int i = 0; i <= n; i++) {
    chmax(ans, dp[i] / 2 + dp[n - dp[i] / 2]);
  }
  cout << ans << '\n';
}
