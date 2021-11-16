#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;

void Main() {
  int n; cin >> n;
  vector<int> a(n + 1), b(n + 1), p(n + 1), d(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    p[a[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  int ans = 1;
  for (int i = 1; i <= n; i++) {
    if (d[i]) continue;
    (ans *= 2) %= MOD;
    int t = i;
    while (!d[t]) {
      d[t] = 1;
      t = p[b[t]];
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
