#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

long long a[N][N];
long long b[N][2], dp_b[N][2];
long long c[N][2], dp_c[N][2];

void chmax(long long &a, long long b) {
  if (a < b) a = b;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  for (int i = 1; i <= n; i++)
  for (int j = 1; j <= n; j++) {
    cin >> a[i][j];
  }
  for (int j = 1; j <= n; j++)
  for (int i = 1; i <= n; i++) {
    b[j][i % 2] += a[i][j];
    c[i][j % 2] += a[i][j];
  }
  for (int i = 1; i <= n; i++)
  for (int k = 0; k <= 1; k++) {
    chmax(dp_b[i][k], max(dp_b[i - 1][0], dp_b[i - 1][1]) + b[i][k]);
    chmax(dp_c[i][k], max(dp_c[i - 1][0], dp_c[i - 1][1]) + c[i][k]);
  }
  long long ans = max(max(dp_b[n][0], dp_b[n][1]), max(dp_c[n][0], dp_c[n][1]));
  cout << ans << '\n';
}
