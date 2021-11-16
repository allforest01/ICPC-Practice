#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 55;

int a[N], sumLeft[N], sumRight[N];
int minLeft[N][N], minRight[N][N];

void chmin(int &a, int b) {
  if (a > b) a = b;
}

void chmax(int &a, int b) {
  if (a < b) a = b;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    sumLeft[i] = a[i] + sumLeft[i - 1];
    for (int j = 1; j <= i; j++) {
      minLeft[i][j] = min(minLeft[i - 1][j], minLeft[i - 1][j - 1] + a[i]);
    }
  }
  for (int i = n; i >= 1; i--) {
    sumRight[i] = a[i] + sumRight[i + 1];
    for (int j = n; j >= i; j--) {
      minRight[i][j] = min(minRight[i + 1][j], minRight[i + 1][j + 1] + a[i]);
    }
  }
  int ans = 0;
  for (int si = 0; si <=  n; si++)
  for (int ri = 0; ri <= si; ri++)
  for (int sj = n + 1; sj >=  1; sj--)
  for (int rj = n + 1; rj >= sj; rj--) {
    if (si + ri + (n - sj + 1) + (n - rj + 1) <= k && si < sj) {
      int comp = sumLeft[si] - minLeft[si][ri] + sumRight[sj] - minRight[sj][rj];
      chmax(ans, comp);
    }
  }
  cout << ans << '\n';
}
