#include <bits/stdc++.h>
using namespace std;

const int N = 805;

#define  less  def_less
#define equal def_equal

int a[N][N];
int less[N][N], equal[N][N];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++)
  for (int j = 1; j <= n; j++) {
    cin >> a[i][j];
  }
  int t = (k * k + 1) / 2;
  auto get = [](int s[N][N], int i1, int j1, int i2, int j2) {
    return s[i2][j2] - s[i1 - 1][j2] - s[i2][j1 - 1] + s[i1 - 1][j1 - 1];
  };
  auto check = [&](int x)->bool {
    memset( less, 0, sizeof( less));
    memset(equal, 0, sizeof(equal));
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      if (a[i][j] <  x)  less[i][j]++;
      if (a[i][j] == x) equal[i][j]++;
       less[i][j] +=  less[i - 1][j] +  less[i][j - 1] -  less[i - 1][j - 1];
      equal[i][j] += equal[i - 1][j] + equal[i][j - 1] - equal[i - 1][j - 1];
    }
    for (int i = 1; i + k - 1 <= n; i++)
    for (int j = 1; j + k - 1 <= n; j++) {
      int l = get( less, i, j, i + k - 1, j + k - 1);
      int e = get(equal, i, j, i + k - 1, j + k - 1);
      if (l + e >= t) return true;
    }
    return false;
  };
  int l = 0, r = 1e9, ans = -1;
  while (l <= r) {
    int x = (l + r) / 2;
    if (check(x)) {
      ans = x;
      r = x - 1;
    }
    else l = x + 1;
  }
  cout << ans << '\n';
}
