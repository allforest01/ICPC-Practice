#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 100005;

int n, m;
pair<ll,ll> v[N];

bool check(ll x) {
  int cnt = 0;
  ll p = INT_MIN;
  for (int i = 1; i <= m; ) {
    p = max(p, v[i].first);
    if (p > v[i].second) {
      i++;
      continue;
    }
    if ((++cnt) == n) return 1;
    p += x;
  }
  return 0;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  freopen("socdist.in" , "r", stdin );
  freopen("socdist.out", "w", stdout);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> v[i].first >> v[i].second;
  }
  sort(v + 1, v + m + 1);
  ll l = 1, r = 1e18, ans = -1;
  while (l <= r) {
    ll m = (l + r) / 2;
    if (check(m)) {
      ans = m;
      l = m + 1;
    }
    else r = m - 1;
  }
  cout << ans << '\n';
}
