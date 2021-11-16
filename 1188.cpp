#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  string s;
  cin >> s;
  int n = s.size();
  s = s + '#';
  s = '#' + s;
  set<int> dif; multiset<int> ans;
  for (int i = 0 ; i <= n; i++) {
    if (s[i] != s[i + 1]) {
      if (dif.size()) {
        ans.insert(i - *prev(dif.end()));
      }
      dif.insert(i);
    }
  }
  int q; cin >> q;
  while (q--) {
    int x; cin >> x;
    if (s[x] == '1') s[x] = '0'; else s[x] = '1';
    auto it = dif.lower_bound(x);
    int cr = *it;
    int pr = *prev(it);
    int pp = *prev(prev(it));
    int nx = *next(it);
    if (x < n && *it == x) {
      dif.erase(it);
      ans.erase(ans.find(nx - x));
      if (pr != x - 1 || pr == 0) {
        if (x > 1) dif.insert(x - 1);
        ans.erase(ans.find(x - pr));
        ans.insert(x - pr - 1);
        ans.insert(nx - x + 1);
      }
      else {
        dif.erase(pr);
        ans.erase(ans.find(1));
        ans.erase(ans.find(pr - pp));
        ans.insert(nx - pp);
      }
    }
    else {
      dif.insert(x);
      ans.erase(ans.find(cr - pr));
      if (cr - x) ans.insert(cr - x);
      if (x > 1 && pr == x - 1) {
        dif.erase(pr);
        ans.erase(ans.find(pr - pp));
        ans.insert(x - pp);
      }
      else {
        dif.insert(x - 1);
        ans.insert(1);
        if (x - 1 - pr) ans.insert(x - 1 - pr);
      }
    }
    cout << *prev(ans.end()) << ' ';
  }
  cout << '\n';
}
