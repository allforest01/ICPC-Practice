#include <bits/stdc++.h>
using namespace std;

const int N = 405;

int a[N][N], sum[N][N];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  freopen("lazy.in" , "r", stdin );
  freopen("lazy.out", "w", stdout);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
  for (int j = 1; j <= n; j++) {
    cin >> a[i][j];
    sum[i][j] = a[i][j] + sum[i][j - 1];
  }
  int ans = 0;
  for (int i = 1; i <= n; i++)
  for (int j = 1; j <= n; j++) {
    int cal = 0;
    for (int k = max(i - m, 1); k <= min(i + m, n); k++) {
      int t = m - abs(i - k);
      int l = max(j - t, 1), r = min(j + t, n);
      cal += sum[k][r] - sum[k][l - 1];
    }
    ans = max(ans, cal);
  }
  cout << ans << '\n';
}
