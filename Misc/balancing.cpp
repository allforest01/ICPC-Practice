#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("balancing.in" , "r", stdin );
  freopen("balancing.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  vector<pair<int,int>> v(n);
  for (auto &i : v) {
    cin >> i.first >> i.second;
  }
  sort(v.begin(), v.end());
  int ans = INT_MAX;
  for (int i = 0; i + 1 < n; i++) {
    int rg_upb = 0, rg_lwb = 0;
    for (int j = 0; j < n; j++) {
      if (v[j].second >= v[i].second) rg_upb++;
      else rg_lwb++;
    }
    int lf_upb = 0, lf_lwb = 0;
    for (int j = 0; j + 1 < n; j++) {
      if (v[j].second >= v[i].second) lf_upb++, rg_upb--;
      else lf_lwb++, rg_lwb--;
      ans = min(ans, max(max(lf_upb, lf_lwb), max(rg_upb, rg_lwb)));
    }
  }
  cout << ans << '\n';
}
