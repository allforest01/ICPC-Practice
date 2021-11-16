#include <bits/stdc++.h>
using namespace std;

const int N = 3005;

long long a[N], dp[N][N];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i + k - 1 <= n; i++) {
      int j = i + k - 1;
      dp[i][j] = max(a[i] - dp[i + 1][j], a[j] - dp[i][j - 1]);
    }
  }
  cout << dp[1][n] << '\n';
}
