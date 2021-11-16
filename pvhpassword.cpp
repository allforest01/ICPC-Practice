#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  string s; int t;
  cin >> s >> t;
  int ans = 0;
  for (auto &i : s) {
    ans += (i - 'a' + t) % 26;
  }
  cout << ans << '\n';
}
