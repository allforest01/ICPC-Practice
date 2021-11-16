#include <bits/stdc++.h>
using namespace std;

#define taskname "FLYCAR"

void ioset() {
  cin.tie(0)->sync_with_stdio(0);
  if (fopen(taskname".INP", "r")) {
    freopen(taskname".INP", "r", stdin );
    freopen(taskname".OUT", "w", stdout);
  }
}

typedef long long ll;

const int N = 405;

int n, m, a[N];
ll ssum[N][N], smax[N][N], dp[N][N];

template<typename T>
void chmin(T &a, T b) {
  if (a > b) a = b;
}

void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    ssum[i][i] = smax[i][i] = a[i];
    for (int j = i + 1; j <= n; j++) {
      ssum[i][j] = ssum[i][j - 1] + a[j];
      smax[i][j] = max(smax[i][j - 1], (ll) a[j]);
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      dp[i][j] = (ll) 1e15;
    }
  }
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      for (int k = 1; k <= m + 1; k++) {
        chmin(dp[i][k], dp[j - 1][k - 1] + smax[j][i] * (i - j + 1) - ssum[j][i]);
      }
    }
  }
  cout << dp[n][m + 1] << '\n';
}

signed main() {
  ioset();
  solve();
}
