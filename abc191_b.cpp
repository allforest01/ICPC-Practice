#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

signed main() {
  // freopen("in" , "r", stdin );
  cin.tie(0)->sync_with_stdio(0);
  int n, x;
  cin >> n >> x;
  for (int i = 0; i < n; i++) {
    int t; cin >> t;
    if (t != x) cout << t << ' ';
  }
  cout << endl;
}
