#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<int> a(n + 5), l(n + 5), r(n + 5);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    int j = i - 1;
    while (j >= 1 && a[j] >= a[i]) j = l[j];
    l[i] = j;
  }
  for (int i = n; i >= 1; i--) {
    int j = i + 1;
    while (j <= n && a[j] >= a[i]) j = r[j];
    r[i] = j;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, (r[i] - l[i] - 1) * a[i]);
  }
  cout << ans << '\n';
}
