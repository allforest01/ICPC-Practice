#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, x;
  cin >> n >> x;
  vector<int> a(n + 1), s(n + 1);
  int res = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a.begin() + 1, a.end());
  for (int i = 1; i <= n; i++) {
    s[i] = a[i] + s[i - 1];
    if (s[i] <= x) res = i;
  }
  cout << res << '\n';
}
