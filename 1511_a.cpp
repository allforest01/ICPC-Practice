#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

void Main() {
  int n; cin >> n;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    if (x != 2) ans++;
  }
  cout << ans << endl;
}

signed main() {
  // freopen("in" , "r", stdin );
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
