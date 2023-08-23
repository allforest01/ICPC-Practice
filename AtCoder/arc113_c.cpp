#include <bits/stdc++.h>
using namespace std;

int main() {
  // freopen("in", "r", stdin);
  cin.tie(0)->sync_with_stdio(0);
  string s;
  cin >> s;
  int n = s.size();
  long long ans = 0;
  map<char,int> cnt;
  for (int i = n - 1; i >= 0; i--) {
    cnt[s[i]]++;
    if (i + 2 < n) {
      if (s[i] == s[i + 1]) {// && s[i] != s[i + 2]) {
        ans += (n - 1) - (i + 1) - (cnt[s[i]] - 2);
        cout << i << ' ' << cnt[s[i]] << ' ' << ans << '\n';
        cnt.clear();
        cnt[s[i]] = (n - 1) - i + 1;
      }
    }
  }
  cout << ans << '\n';
}
