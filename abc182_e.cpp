#include <bits/stdc++.h>
using namespace std;

#define left def_left
#define right def_right

const int N = 1505;

int a[N][N], up[N][N], down[N][N], left[N][N], right[N][N];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m, nbulb, nblock;
  cin >> n >> m >> nbulb >> nblock;
  for (int i = 0; i < nbulb; i++) {
    int x, y;
    cin >> x >> y;
    up[x][y] = down[x][y] = left[x][y] = right[x][y] = 1;
  }
  for (int i = 0; i < nblock; i++) {
    int x, y;
    cin >> x >> y;
    a[x][y] = 2;
  }
  for (int i = 1; i <= n; i++)
  for (int j = 1; j <= m; j++) {
    if (a[i][j] == 0) {
      if (down[i - 1][j]  == 1) down[i][j]  = 1;
      if (right[i][j - 1] == 1) right[i][j] = 1;
    }
  }
  for (int i = n; i >= 1; i--)
  for (int j = m; j >= 1; j--) {
    if (a[i][j] == 0) {
      if (up[i + 1][j]   == 1) up[i][j]   = 1;
      if (left[i][j + 1] == 1) left[i][j] = 1;
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++)
  for (int j = 1; j <= m; j++) {
    if (up[i][j] == 1 || down[i][j] == 1 || left[i][j] == 1 || right[i][j] == 1) {
      ans++;
    }
  }
  cout << ans << '\n';
}
