#include <bits/stdc++.h>
using namespace std;

#define int long long

void Main() {
  int n; cin >> n;
  string s;
  cin >> s;
  int cnt = 0, ans = 0;
  for (auto &i : s) {
    ans += i - '0';
    if (i != '0') cnt++;
  }
  cout << ans + cnt - (s[n - 1] != '0') << '\n';
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}