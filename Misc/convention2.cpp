#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  freopen("convention2.in" , "r", stdin );
  freopen("convention2.out", "w", stdout);
  int n; cin >> n;
  vector<array<int,3>> v(n);
  for (int i = 0; i < n; i++) {
    int a, t;
    cin >> a >> t;
    v[i] = {a, t, i + 1};
  }
  sort(v.begin(), v.end());
  set<array<int,3>> s;
  s.insert({v[0][2], v[0][0], v[0][1]});
  int time = v[0][0], pos = 0, ans = 0;
  while (pos < n) {
    int a = (*s.begin())[1], t = (*s.begin())[2], i = (*s.begin())[0];
    s.erase(s.begin());
    ans = max(ans, time - a);
    time += t;
    while (pos + 1 < n && v[pos + 1][0] <= time) {
      pos++;
      s.insert({v[pos][2], v[pos][0], v[pos][1]});
    }
    if (!s.size()) {
      pos++;
      if (pos < n) {
        time = v[pos][0];
        s.insert({v[pos][2], v[pos][0], v[pos][1]});
      }
    }
  }
  cout << ans << '\n';
}
