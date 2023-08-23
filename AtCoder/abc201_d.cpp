#include <bits/stdc++.h>
using namespace std;

const int N = 2005;

int a[N][N], dp[N][N];

void chmax(int &a, int b) {
  if (a < b) a = b;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
  for (int j = 1; j <= m; j++) {
    char c; cin >> c;
    a[i][j] = (c == '+' ? 1 : -1);
  }
  for (int i = n; i >= 1; i--)
  for (int j = m; j >= 1; j--) {
    if (i == n && j == m) continue;
    dp[i][j] = INT_MIN / 2;
    if (i < n) chmax(dp[i][j], a[i + 1][j] - dp[i + 1][j]);
    if (j < m) chmax(dp[i][j], a[i][j + 1] - dp[i][j + 1]);
  }
  for (int i = 1; i <= n; i++)
  for (int j = 1; j <= m; j++) {
    cout << setw(2) << dp[i][j] << " \n"[j == m];
  }
  if (dp[1][1] == 0) {
    cout << "Draw" << '\n';
    return 0;
  }
  string a = "Takahashi", b = "Aoki";
  if ((n + m - 2) % 2) swap(a, b);
  cout << (dp[1][1] > 0 ? a : b) << '\n';
}
