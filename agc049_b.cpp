#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  string s, t;
  cin >> n >> s >> t;
  vector<int> last;
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == '1') last.push_back(i);
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    while (last.size() && i >= last.back()) last.pop_back();
    if (s[i] == '0' && t[i] == '1') {
      if (!last.size()) {
        cout << -1 << '\n';
        return 0;
      }
      ans += last.back() - i;
      s[i] = '1';
      s[last.back()] = '0';
      last.pop_back();
    }
    else if (s[i] == '1' && t[i] == '0') {
      if (i + 1 == n) {
        cout << -1 << '\n';
        return 0;
      }
      if (s[i + 1] != '1') {
        if (!last.size()) {
          cout << -1 << '\n';
          return 0;
        }
        ans += last.back() - i - 1;
        s[i + 1] = '1';
        s[last.back()] = '0';
        last.pop_back();
      }
      s[i] = s[i + 1] = '0';
      ans++;
    }
  }
  cout << ans << '\n';
}
