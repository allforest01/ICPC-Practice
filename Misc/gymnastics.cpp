#include <bits/stdc++.h>
using namespace std;

const int N = 25;

int a[N][N];

int main() {
  freopen("gymnastics.in" , "r", stdin );
  freopen("gymnastics.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  int k, n;
  cin >> k >> n;
  for (int i = 1; i <= k; i++) {
    for (int j = 1; j <= n; j++) {
      int x; cin >> x;
      a[i][x] = j;
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++)
  for (int j = 1; j <= n; j++) {
    bool flag = 0;
    for (int l = 1; l <= k; l++) {
      if (a[l][i] <= a[l][j]) {
        flag = 1;
        break;
      }
    }
    if (!flag) {
      ans++;
      // cout << i << ' ' << j << '\n';
    }
  }
  cout << ans << '\n';
}
