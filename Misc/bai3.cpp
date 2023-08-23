#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) {
    string s;
    cin >> s;
    int n = s.size();
    string ans, cur;
    for (int i = 0; i < n; i++) {
      if (s[i] == s[n - i - 1]) {
        cur += s[i];
      }
      else {
        if (cur.size() > ans.size()) {
          ans = cur;
        }
        if (i >= (n + 1) / 2 - 1) break;
        cur = "";
      }
    }
    if (cur.size() > ans.size()) {
      ans = cur;
    }
    cout << ans << '\n';
  }
}
