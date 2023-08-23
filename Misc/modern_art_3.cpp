#include <bits/stdc++.h>
using namespace std;

const int N = 305;

int a[N], dp[N][N];

void chmin(int &a, int b) {
  if (a > b) a = b;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  freopen("in", "r", stdin);
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int len = 1; len <= n; len++) {
    for (int i = 1; i + len - 1 <= n; i++) {
      int j = i + len - 1;
      dp[i][j] = len;
      for (int k = i; k < j; k++) {
        chmin(dp[i][j], dp[i][k] + dp[k + 1][j]);
      }
      int l = i, r = j;
      while (l + 1 <= j && a[l + 1] == a[i]) l++;
      while (r - 1 >= i && a[r - 1] == a[j]) r--;
      if (l >= r) dp[i][j] = 1;
      else chmin(dp[i][j], dp[l + 1][r - 1] + 1 + (a[i] != a[j]));
    }
  }
  cout << dp[1][n] << '\n';
  /*for (int i = 1; i <= n; i++)
  for (int j = 1; j <= n; j++) {
    if (dp[i][j] == 0x3f3f3f3f) cout << setw(2) << '!' << " \n"[j == n];
    else cout << setw(2) << dp[i][j] << " \n"[j == n];
  }*/
}
