#include <bits/stdc++.h>
using namespace std;

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<array<int,2>> a(n);
  int ans = INT_MAX, cnt = 1;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    a[i] = {x, i + 1};
    ans = min(ans, x + 1);
  }
  sort(a.begin(), a.end(), greater<array<int,2>>());
  set<int> pos; pos.insert(0); pos.insert(n + 1);
  map<int,int> len; len[n] = 1;
  for (int i = 0; i < n; i++) {
    int p = a[i][1];
    auto nxt = pos.lower_bound(p);
    auto prv = prev(nxt);
    int old_len = *nxt - *prv - 1;
    len[old_len]--;
    if (len[old_len] == 0) len.erase(old_len);
    int new_len_lf = p - *prv - 1;
    int new_len_ri = *nxt - p - 1;
    if (new_len_lf) len[new_len_lf]++;
    if (new_len_ri) len[new_len_ri]++;
    pos.insert(p);
    if (len.size() == 1 && len.begin()->second >= cnt) {
      ans = i + 1 == n ? a[i][0] + 1 : a[i + 1][0] + 1;
      cnt = len.begin()->second;
    }
  }
  cout << ans << '\n';
}
