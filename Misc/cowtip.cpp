#include <bits/stdc++.h>
using namespace std;

const int N = 15;

int a[N][N];

void flip(int n, int m) {
  for (int i = 1; i <= n; i++)
  for (int j = 1; j <= m; j++) {
    a[i][j] ^= 1;
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  freopen("cowtip.in" , "r", stdin );
  freopen("cowtip.out", "w", stdout);
  int n; cin >> n;
  for (int i = 1; i <= n; i++)
  for (int j = 1; j <= n; j++) {
    char c; cin >> c;
    a[i][j] = c - '0';
  }
  int ans = 0;
  for (int i = n; i >= 1; i--)
  for (int j = n; j >= 1; j--) {
    if (a[i][j]) {
      flip(i, j);
      ans++;
    }
  }
  cout << ans << '\n';
}
