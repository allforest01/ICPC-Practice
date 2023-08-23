#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; string s;
  cin >> n >> s;
  int ans = -1;
  for (int i = 0; i + 1 < s.size(); i++) {
    if (s[0] != s[i] && s[i + 1] != s.back()) {
      ans = 2;
    }
  }
  if (s[0] != s.back()) ans = 1;
  cout << ans << '\n';
}
