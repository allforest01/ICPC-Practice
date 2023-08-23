#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)((x).size())

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; string t;
  cin >> n >> t;
  if (t == "1") {
    cout << "20000000000" << '\n';
    return 0;
  }
  string s;
  int cnt = 0;
  while (sz(s) < sz(t)) {
    s += "110";
    cnt++;
  }
  if (sz(s) == sz(t) && s == t) {
    cout << 10000000000LL - cnt + 1 << '\n';
    return 0;
  }
  for (int i = 0; i <= 2; i++) {
    if (sz(s) - i < sz(t)) {
      s += "110";
      cnt++;
    }
    if (s.substr(i, sz(t)) == t) {
      cout << 10000000000LL - cnt + 1 << '\n';
      return 0;
    }
  }
  cout << 0 << '\n';
}
