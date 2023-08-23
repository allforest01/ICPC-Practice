#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int a[N], dp[N][25][5];

void chmax(int &a, int b) {
  if (a < b) a = b;
}

int check(int a, int b) {
  if ((a + 1) % 3 == b) return 1;
  return 0;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  freopen("hps.in" , "r", stdin );
  freopen("hps.out", "w", stdout);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    char c; cin >> c;
    if (c == 'H') a[i] = 0;
    if (c == 'S') a[i] = 1;
    if (c == 'P') a[i] = 2;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++)
  for (int j = 0; j <= m; j++)
  for (int k = 0; k <= 2; k++)
  for (int l = 0; l <= 2; l++) {
    if (k != l && j == m) continue;
    chmax(dp[i][j][k], dp[i - 1][j + (k != l)][l] + check(k, a[i]));
    ans = max(ans, dp[i][j][k]);
  }
  cout << ans << '\n';
}
