#include <bits/stdc++.h>
using namespace std;

const int N = 5005;

int n, k;
int a[N], cost[N][N];
int dp[N][N], opt[N][N];
int test[N][N];

template<typename T>
bool chmin(T &a, T b) {
  return a > b ? a = b, 1 : 0;
}

void compute(int k, int l, int r, int optl, int optr) {
  if (l > r) return;
  int m = (l + r) / 2, opt = optl;
  for (int i = optl; i <= min(optr, m); i++) {
    if (chmin(dp[k][m], dp[k - 1][i - 1] + cost[m][m] - cost[m][i - 1])) {
      opt = i;
    }
  }
  compute(k, l, m - 1, optl, opt);
  compute(k, m + 1, r, opt, optr);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
//  freopen("in" , "r", stdin );
//  freopen("ans", "w", stdout);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cost[i][j] = cost[i][j - 1];
      if (a[j] > a[i] && j < i) {
        cost[i][j]++;
        test[i][j] = 1;
      }
    }
    for (int j = 1; j <= n; j++) {
      cost[i][j] += cost[i - 1][j];
    }
  }
//  memset(dp, 0x3f, sizeof(dp)); dp[0][0] = 0;
//  for (int k = 1; k <= n; k++) {
//    compute(k, 1, n, 1, n);
//  }
//  for (int k = 1; k <= n; k++) {
//    for (int i = 1; i <= n; i++) {
//      for (int j = 1; j <= i; j++) {
//        if (chmin(dp[k][i], dp[k - 1][j - 1] + cost[i][i] - cost[i][j - 1])) {
//          opt[k][i] = j;
//        }
//      }
//    }
//  }
//  cout << dp[k][n] << '\n';
}
