#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x).size()

int main() {
  // cin.tie(0)->sync_with_stdio(0);
  int n; string s;
  cin >> n >> s;
  set<char> d;
  for (auto &i : s) d.insert(i);
  int max_type = sz(d);
  d.clear();
  map<char,int> m;
  int ans = INT_MAX;
  for (int i = 0, j = -1; i < sz(s); i++) {
    while (j + 1 < sz(s) && sz(d) < max_type) {
      j++;
      if (m[s[j]] == 0) {
        d.insert(s[j]);
      }
      m[s[j]]++;
    }
    if (sz(d) == max_type) ans = min(ans, j - i + 1);
    m[s[i]]--;
    if (m[s[i]] == 0) {
      d.erase(s[i]);
    }
  }
  cout << ans << '\n';
}
