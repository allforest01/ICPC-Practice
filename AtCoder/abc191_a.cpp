#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

signed main() {
  // freopen("in" , "r", stdin );
  cin.tie(0)->sync_with_stdio(0);
  double v, t, s, d;
  cin >> v >> t >> s >> d;
  if (t <= d / v && d / v <= s) {
    cout << "No" << endl;
  }
  else {
    cout << "Yes" << endl;
  }
}
