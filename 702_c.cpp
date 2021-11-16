#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m);
  for (auto &i : a) cin >> i;
  for (auto &i : b) cin >> i;
  sort(b.begin(), b.end());
  int ans = 0;
  for (auto &i : a) {
    int cal = INT_MAX;
    auto it = lower_bound(b.begin(), b.end(), i);
    if (it != b.end()) {
      cal = min(cal, abs(i - *it));
    }
    if (it != b.begin()) {
      cal = min(cal, abs(i - *prev(it)));
    }
    ans = max(ans, cal);
  }
  cout << ans << '\n';
}
