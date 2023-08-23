#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 405;

int a[N];
ll sum[N], dp[N][N];

template<typename T>
bool chmin(T &a, T b) {
  return a > b ? a = b, 1 : 0;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  memset(dp, 0x3f, sizeof(dp));
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum[i] = sum[i - 1] + a[i];
    dp[i][i] = 0;
  }
  for (int i = n; i >= 1; i--) {
    for (int j = i + 1; j <= n; j++) {
      for (int k = i; k < j; k++) {
        chmin(dp[i][j], dp[i][k] + dp[k + 1][j] + sum[j] - sum[i - 1]);
      }
    }
  }
  cout << dp[1][n] << '\n';
}
