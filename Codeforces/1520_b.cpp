#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

void Main() {
  int n; cin >> n;
  int ans = 0;
  for (int i = 1; i <= 9; i++) {
    int t = 0;
    for (int j = 1; j <= i; j++) {
      t = t * 10 + 1;
    }
    for (int j = 1; j <= 9; j++) {
      if (t * j <= n) ans++;
    }
  }
  cout << ans << endl;
}

signed main() {
  // freopen("in" , "r", stdin );
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
