#include <bits/stdc++.h>
using namespace std;

#define taskname "CANDY"

void ioset() {
  cin.tie(0)->sync_with_stdio(0);
  if (fopen(taskname".INP", "r")) {
    freopen(taskname".INP", "r", stdin );
    freopen(taskname".OUT", "w", stdout);
  }
}

const int N = 505;
const int M = 100005;

int n, a[N], dp[N][M];

template<typename T>
void chmax(T &a, T b) {
  if (a < b) a = b;
}

void solve() {
  cin >> n;
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      dp[i][j] = -1e9;
    }
  }
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= sum; j++) {
      dp[i][j] = dp[i - 1][j];
      chmax(dp[i][j], dp[i - 1][j + a[i]] + a[i]);
      chmax(dp[i][j], dp[i - 1][abs(j - a[i])] + a[i]);
    }
  }
  cout << sum - dp[n][0] / 2 << '\n';
}

signed main() {
  ioset();
  solve();
}
