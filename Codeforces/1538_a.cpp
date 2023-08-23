#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

void Main() {
  int n; cin >> n;
  vector<int> a(n + 1);
  int mi = 2e9, ma = -2e9;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    mi = min(mi, a[i]);
    ma = max(ma, a[i]);
  }
  int pi = -1, pa = -1;
  for (int i = 1; i <= n; i++) {
    if (mi == a[i]) pi = i;
    if (ma == a[i]) pa = i;
  }
  if (pi > pa) swap(pi, pa);
  int ans = min(min(pa, n - pi + 1), pi + n - pa + 1);
  cout << ans << endl;
}

signed main() {
  // freopen("in" , "r", stdin );
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
