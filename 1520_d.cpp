#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

void Main() {
  int n; cin >> n;
  map<int, int> m;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    ans += m[x - i];
    m[x - i]++;
  }
  cout << ans << endl;
}

signed main() {
  // freopen("in" , "r", stdin );
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
