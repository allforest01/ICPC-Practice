#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<int> a(n + 2);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<int> ls(n + 2), lt = a;
  for (int i = 1; i <= n; i++) {
    int t = max(lt[i - 1] + 1, lt[i]) - lt[i];
    ls[i] = ls[i - 1] + t;
    lt[i] += t;
  }
  vector<int> rs(n + 2), rt = a;
  for (int i = n; i >= 1; i--) {
    int t = max(rt[i + 1] + 1, rt[i]) - rt[i];
    rs[i] = rs[i + 1] + t;
    rt[i] += t;
  }
  int ans = LLONG_MAX;
  for (int i = 0; i <= n; i++) {
    ans = min(ans, ls[i] + rs[i + 1] + (lt[i] == rt[i + 1]));
  }
  cout << ans << '\n';
}
