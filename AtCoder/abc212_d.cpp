#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int q; cin >> q;
  set<pair<int,int>> s;
  int sum = 0;
  while (q--) {
    int t; cin >> t;
    if (t == 1) {
      int x; cin >> x;
      x -= sum;
      auto it = s.lower_bound(make_pair(x, 0));
      if (it != s.end() && it->first == x) {
        int sc = it->second;
        s.erase(it);
        s.insert(make_pair(x, sc + 1));
      }
      else s.insert(make_pair(x, 1));
    }
    else if (t == 2) {
      int x; cin >> x;
      sum += x;
    }
    else if (t == 3) {
      auto it = s.begin();
      cout << it->first + sum << '\n';
      int fi = it->first, sc = it->second;
      s.erase(it);
      if (sc > 1) s.insert(make_pair(fi, sc - 1));
    }
  }
}
