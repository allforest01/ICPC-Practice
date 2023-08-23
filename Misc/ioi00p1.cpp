#include <bits/stdc++.h>
using namespace std;

const int N = 5005;

int dp[5][N];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  string s1;
  cin >> s1;
  string s2 = s1;
  reverse(s2.begin(), s2.end());
  s1 = '$' + s1;
  s2 = '$' + s2;
  for (int i = 1; i <= n; i++)
  for (int j = 1; j <= n; j++) {
    if (s1[i] == s2[j]) {
      dp[i % 2][j] = dp[(i - 1) % 2][j - 1] + 1;
    }
    else {
      dp[i % 2][j] = max(dp[(i - 1) % 2][j], dp[i % 2][j - 1]);
    }
  }
  cout << n - dp[n % 2][n] << '\n';
}
