#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<int> a(n), b(n), c(n);
  for (auto &i : a) cin >> i;
  for (auto &i : b) cin >> i;
  for (auto &i : c) cin >> i;
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  sort(c.begin(), c.end());
  int i = 0, j = 0, k = 0, ans = 0;
  while (i < n) {
    while (j < n && b[j] <= a[i]) j++;
    while (j < n && k < n && c[k] <= b[j]) k++;
    if (j < n && k < n && b[j] > a[i] && c[k] > b[j]) {
      ans++; j++; k++;
    }
    i++;
  }
  cout << ans << '\n';
}
