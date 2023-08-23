#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  freopen("in" , "r", stdin );
  freopen("out", "w", stdout);
  for (string inp; getline(cin, inp); ) {
    stringstream ss(inp);
    vector<int> a;
    for (int t; ss >> t; ) {
      a.push_back(t);
    }
    a.pop_back();
    int n = a.size();
    int ans = INT_MIN, prod = 1;
    set<int> s;
    s.insert(1);
    for (int i = 0; i < n; i++) {
      if (a[i] == 0) {
        ans = max(ans, 0LL);
        prod = 1LL;
        s.clear();
        s.insert(1);
      }
      else {
        prod *= a[i];
        ans = max(ans, prod);
        ans = max(ans, prod / *s.begin());
        ans = max(ans, prod / *s.rbegin());
        s.insert(prod);
      }
    }
    cout << ans << '\n';
  }
}
