#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<string> s(n);
  vector<int> t(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i] >> t[i];
  }
  string x; cin >> x;
  int ans = 0;
  bool flag = 0;
  for (int i = 0; i < n; i++) {
    if (flag) ans += t[i];
    if (s[i] == x) flag = 1;
  }
  cout << ans << '\n';
}
