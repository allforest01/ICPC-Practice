#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int a[N][N], s[N][N];

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
  for (int j = 1; j <= m; j++) {
    cin >> a[i][j];
    if (a[i][j]) s[i][j] = a[i][j] + s[i - 1][j];
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    vector<int> l(m + 2), r(m + 2);
    for (int j = 1; j <= m; j++) {
      l[j] = j - 1;
      while (l[j] >= 1 && s[i][l[j]] >= s[i][j]) l[j] = l[l[j]];
    }
    for (int j = m; j >= 1; j--) {
      r[j] = j + 1;
      while (r[j] <= m && s[i][r[j]] >= s[i][j]) r[j] = r[r[j]];
    }
    for (int j = 1; j <= m; j++) {
      ans = max(ans, s[i][j] * (r[j] - l[j] - 1));
    }
  }
  cout << ans << '\n';
}