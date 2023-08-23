#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

void Main() {
  int a, b;
  cin >> a >> b;
  int ans = 0;
  while (a || b) {
    ans += b - a;
    b /= 10;
    a /= 10;
  }
  cout << ans << endl;
}

signed main() {
  // freopen("in" , "r", stdin );
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
