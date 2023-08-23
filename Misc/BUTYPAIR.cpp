#include <bits/stdc++.h>
using namespace std;

#define int long long

int Main() {
  int n; cin >> n;
  map<int,int> cnt;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    cnt[x]++;
  }
  int ans = n * (n - 1);
  for (auto &i : cnt) {
    ans -= i.second * (i.second - 1);
  }
  cout << ans << '\n';
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
