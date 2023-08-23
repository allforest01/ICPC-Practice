#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

signed main() {
  // freopen("in" , "r", stdin );
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  set<int> s;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    auto it = s.lower_bound(x);
    if (it != s.end()) s.erase(it);
    s.insert(x);
  }
  cout << s.size() << endl;
}
