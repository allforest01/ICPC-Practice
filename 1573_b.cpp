#include <bits/stdc++.h>
using namespace std;

#define int long long

void chmin(int &a, int b) {
  if (a > b) a = b;
}

void Main() {
  int n; cin >> n;
  vector<int> a(n + 1), b(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  vector<int> min_pos(2 * n + 1, INT_MAX);
  for (int i = 1; i <= n; i++) {
    min_pos[b[i]] = i;
  }
  for (int i = 2 * n - 1; i >= 1; i--) {
    chmin(min_pos[i], min_pos[i + 1]);
  }
  int ans = INT_MAX;
  for (int i = 1; i <= n; i++) {
    chmin(ans, i - 1 + min_pos[a[i]] - 1);
  }
  cout << ans << '\n';
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}