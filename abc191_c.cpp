#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int N = 15;

char a[N][N];

signed main() {
  // freopen("in" , "r", stdin );
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
  for (int j = 1; j <= m; j++) {
    cin >> a[i][j];
  }
  int ans = 0;
  for (int i = 2; i <= n - 1; i++)
  for (int j = 2; j <= m - 1; j++) {
    if (a[i][j] == '.') continue;
    if (a[i - 1][j] == '.' && !(a[i][j - 1] == '#' && a[i - 1][j - 1] == '.')) ans++;
    if (a[i][j - 1] == '.' && !(a[i - 1][j] == '#' && a[i - 1][j - 1] == '.')) ans++;
    if (a[i + 1][j] == '.' && !(a[i][j - 1] == '#' && a[i + 1][j - 1] == '.')) ans++;
    if (a[i][j + 1] == '.' && !(a[i - 1][j] == '#' && a[i - 1][j + 1] == '.')) ans++;
  }
  cout << ans << endl;
}
