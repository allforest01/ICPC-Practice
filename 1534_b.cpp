#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

void Main() {
  int n; cin >> n;
  vector<int> a(n + 2);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
      int t = max(a[i - 1], a[i + 1]);
      ans += a[i] - t;
      a[i] = t;
    }
  }
  for (int i = 1; i <= n + 1; i++) {
    ans += abs(a[i] - a[i - 1]);
  }
  cout << ans << endl;
}

signed main() {
  // freopen("in" , "r", stdin );
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
