#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("pairup.in" , "r", stdin );
  freopen("pairup.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<pair<int,int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].second >> a[i].first;
  }
  sort(a.begin(), a.end());
  int l = 0, r = n - 1, ans = 0;
  while (l <= r) {
    if (l != r) {
      int t = min(a[l].second, a[r].second);
      ans = max(ans, a[l].first + a[r].first);
      a[l].second -= t;
      a[r].second -= t;
      if (a[l].second == 0) l++;
      if (a[r].second == 0) r--;
    }
    else {
      ans = max(ans, a[l].first * 2);
      break;
    }
  }
  cout << ans << '\n';
}
