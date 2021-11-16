#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<char> a(n), b(n);
  for (auto &i : a) cin >> i;
  for (auto &i : b) cin >> i;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == b[i]) ans++;
  }
  cout << ans << '\n';
}
