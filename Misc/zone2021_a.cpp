#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  string s;
  cin >> s;
  int ans = 0;
  for (int i = 0; i + 3 < s.size(); i++) {
    if (s.substr(i, 4) == "ZONe") ans++;
  }
  cout << ans << '\n';
}
