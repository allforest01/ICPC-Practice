#include <bits/stdc++.h>
using namespace std;

int main() {
  int m, n, k;
  cin >> m >> n >> k;
  vector<int> a(m + 1);
  for (int i = 1; i <= m; i++) {
    cin >> a[i];
  }
  sort(a.begin() + 1, a.end());
  vector<long long> s(m + 1);
  for (int i = 1; i <= m; i++) {
    s[i] = a[i] + s[i - 1];
  }
  long long ans = -2;
  for (int i = 1; i + n - 1 <= m; i++) {
    if (a[i + n - 1] - a[i] <= k) {
      ans = max(ans, s[i + n - 1] - s[i - 1]);
    }
  }
  cout << ans << '\n';
}