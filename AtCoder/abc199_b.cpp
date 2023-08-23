#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<int> a(n), b(n);
  for (auto &i : a) cin >> i;
  for (auto &i : b) cin >> i;
  int l = INT_MIN, r = INT_MAX;
  for (int i = 0; i < n; i++) {
    l = max(l, a[i]);
    r = min(r, b[i]);
  }
  cout << max(0, r - l + 1) << '\n';
}
