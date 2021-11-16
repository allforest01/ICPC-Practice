#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("blist.in" , "r", stdin );
  freopen("blist.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  int a[1001]{};
  int n; cin >> n;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int s, t, b;
    cin >> s >> t >> b;
    for (int j = s; j <= t; j++) {
      a[j] += b;
      ans = max(ans, a[j]);
    }
  }
  cout << ans << '\n';
}
