#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  if (n % 2) {
    cout << "still running" << '\n';
    return 0;
  }
  vector<int> a(n);
  for (auto &i : a) cin >> i;
  int ans = 0;
  for (int i = 1; i < n; i += 2) {
    ans += a[i] - a[i - 1];
  }
  cout << ans << '\n';
}
