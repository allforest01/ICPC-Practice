#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<long long> a(n), b(m);
  for (auto &i : a) cin >> i;
  for (auto &i : b) cin >> i;
  sort(a.begin(), a.end(), greater<int>());
  sort(b.begin(), b.end(), greater<int>());
  if (a[0] > b[m - 1]) {
    cout << -1 << '\n';
    return 0;
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans += a[i] * m;
  }
  vector<int> c(m);
  for (int i = 0; i + 1 < m; i++) {
    c[i] = a[0];
  }
  for (int i = 0; i + 1 < m; i++) {
    if (b[i] < c[i]) {
      cout << -1 << '\n';
      return 0;
    }
    ans += b[i] - c[i];
  }
  if (b[m - 1] > a[0]) {
    ans += b[m - 1] - a[1];
  }
  cout << ans << '\n';
}
