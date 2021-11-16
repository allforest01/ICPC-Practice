#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  int l = 1, r = 1e9, ans = -1;
  while (l <= r) {
    int m = (l + r) / 2, c = 0;
    for (auto &i : a) {
      c += (i - 1) / m; // "rounding up" ... :(
    }
    if (c <= k) {
      r = m - 1;
      ans = m;
    }
    else {
      l = m + 1;
    }
  }
  cout << ans << '\n';
}
