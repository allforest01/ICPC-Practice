#include <bits/stdc++.h>
using namespace std;

#define taskname "FLOODFILL"

void ioset() {
  cin.tie(0)->sync_with_stdio(0);
  if (fopen(taskname".INP", "r")) {
    freopen(taskname".INP", "r", stdin );
    freopen(taskname".OUT", "w", stdout);
  }
}

const int N = 5005;

int n, a[N], dp[N][N][5];

template<typename T>
void chmin(T &a, T b) {
  if (a > b) a = b;
}

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  n = unique(a + 1, a + n + 1) - (a + 1);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      dp[i][j][1] = dp[i][j][2] = 1e9;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i; j >= 1; j--) {
      if (j == i) dp[j][i][1] = dp[j][i][2] = 0;
      else {
        dp[j][i][1] = min(dp[j + 1][i][1] + (a[j] != a[j + 1]), dp[j + 1][i][2] + (a[j] != a[i]));
        dp[j][i][2] = min(dp[j][i - 1][1] + (a[i] != a[j]), dp[j][i - 1][2] + (a[i] != a[i - 1]));
      }
    }
  }
  cout << min(dp[1][n][1], dp[1][n][2]) << '\n';
}

signed main() {
  ioset();
  solve();
}
