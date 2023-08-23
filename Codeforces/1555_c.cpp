#include <bits/stdc++.h>
using namespace std;

void Main() {
  int n; cin >> n;
  vector<vector<int>> a(5, vector<int>(n + 5));
  vector<int> lsum(n + 5), rsum(n + 5);
  for (int i = 1; i <= 2; i++)
  for (int j = 1; j <= n; j++) {
    cin >> a[i][j];
  }
  for (int i = 1; i <= n; i++) {
    lsum[i] = a[2][i] + lsum[i - 1];
  }
  for (int i = n; i >= 1; i--) {
    rsum[i] = a[1][i] + rsum[i + 1];
  }
  int ans = INT_MAX;
  for (int i = 1; i <= n; i++) {
    ans = min(ans, max(lsum[i - 1], rsum[i + 1]));
  }
  cout << ans << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
