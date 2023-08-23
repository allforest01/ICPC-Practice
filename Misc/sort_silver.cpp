#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  freopen("sort.in" , "r", stdin );
  freopen("sort.out", "w", stdout);
  int n; cin >> n;
  vector<pair<int,int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a.begin(), a.end());
  int ans = 1;
  for (int i = 0; i < n; i++) {
    ans = max(ans, a[i].second - i + 1);
  }
  cout << ans << '\n';
}
