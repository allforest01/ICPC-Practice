#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 200005;
const int blz = sqrt(N);

int a[N], blsum[N];

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    blsum[i / blz] += a[i];
  }
  while (q--) {
    int t, u, v;
    cin >> t >> u >> v;
    if (t == 1) {
      u--;
      int t = v - a[u];
      a[u] = v;
      blsum[u / blz] += t;
    }
    else {
      u--; v--;
      if (u / blz == v / blz) {
        int ans = 0;
        for (int i = u; i <= v; i++) {
          ans += a[i];
        }
        cout << ans << '\n';
        continue;
      }
      int ans = 0;
      for (int i = u; i < (u / blz + 1) * blz; i++) {
        ans += a[i];
      }
      for (int i = u / blz + 1; i <= v / blz - 1; i++) {
        ans += blsum[i];
      }
      for (int i = v / blz * blz; i <= v; i++) {
        ans += a[i];
      }
      cout << ans << '\n';
    }
  }
}
