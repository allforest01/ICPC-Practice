#include <bits/stdc++.h>
using namespace std;

void Main() {
  int n; cin >> n;
  vector<int> a(n);
  for (auto &i : a) cin >> i;
  sort(a.begin(), a.end());
  int ans = 0, flag = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] > a[0]) {
      ans++;
      if ((a[i] + 1) / 2 <= a[0]) flag = 1;
    }
  }
  if (flag) cout << n << '\n';
  else cout << ans << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}