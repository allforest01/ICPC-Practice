#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  freopen("diamond.in" , "r", stdin );
  freopen("diamond.out", "w", stdout);
  int n, k;
  cin >> n >> k;
  vector<int> a(n), d(n), m(n);
  for (auto &i : a) cin >> i;
  sort(a.begin(), a.end());
  // for (auto &i : a) cout << i << ' '; cout << '\n';
  int ans = 0;
  for (int i = 0, j = -1; i < n; i++) {
    if (j < i) {
      j = i;
      d[i] = i;
      m[i] = 1;
      if (i > 0) m[i] = max(m[i], m[i - 1]);
    }
    while (j + 1 < n && abs(a[i] - a[j + 1]) <= k) {
      j++;
      d[j] = i;
      m[j] = max(j - i + 1, m[j - 1]);
    }
    ans = max(ans, (j - i + 1) + (i > 0 ? m[i - 1] : 0));
  }
  // for (auto &i : d) cout << i << ' '; cout << '\n';
  cout << ans << '\n';
}
