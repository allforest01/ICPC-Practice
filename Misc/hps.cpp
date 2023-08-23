#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int sum[N][3];

int main() {
  freopen("hps.in" , "r", stdin );
  freopen("hps.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    char c; cin >> c;
    if (c == 'H') sum[i][0]++;
    if (c == 'S') sum[i][1]++;
    if (c == 'P') sum[i][2]++;
    for (int j = 0; j <= 2; j++) {
      sum[i][j] += sum[i - 1][j];
    }
  }
  int ans = 0;
  for (int i = 0; i <= n; i++)
  for (int j = 0; j <= 2; j++)
  for (int k = 0; k <= 2; k++) {
    ans = max(ans, sum[i][j] + sum[n][k] - sum[i][k]);
  }
  cout << ans << '\n';
}
