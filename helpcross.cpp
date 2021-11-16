#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  freopen("helpcross.in" , "r", stdin );
  freopen("helpcross.out", "w", stdout);
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  sort(a.begin(), a.end());
  vector<pair<int,int>> b(m);
  for (auto &i : b) {
    cin >> i.first >> i.second;
  }
  sort(b.begin(), b.end());
  int ans = 0;
  multiset<int> s;
  for (int i = 0, j = 0; i < n; i++) {
    while (j < m && b[j].first <= a[i]) {
      s.insert(b[j].second);
      j++;
    }
    auto it = s.lower_bound(a[i]);
    if (it != s.end()) {
      s.erase(it);
      ans++;
    }
  }
  cout << ans << '\n';
}
