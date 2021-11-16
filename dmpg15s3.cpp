#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int a[N], b[N], dp[N];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int m; cin >> m;
  for (int i = 1; i <= m; i++) {
    int p, d;
    cin >> p >> d;
    b[p + 1] = d;
  }
  dp[1] = a[1];
  for (int i = 2; i <= n; i++) {
    dp[i] = max(dp[i - 2], dp[i - 1] - b[i]) + a[i];
  }
  cout << dp[n] << '\n';
}
