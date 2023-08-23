#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  int n; cin >> n;
  vector<pair<ll,ll>> pl, pr;
  for (int i = 0; i < n; i++) {
    ll p, t, d;
    cin >> p >> t >> d;
    pl.push_back({p - d - 1, t});
    pl.push_back({p - d    , 0});
    pl.push_back({p + d    , 0});
    pl.push_back({p + d + 1, 0});
    pr.push_back({p - d - 1, 0});
    pr.push_back({p - d    , 0});
    pr.push_back({p + d    , 0});
    pr.push_back({p + d + 1, t});
  }
  sort(pl.begin(), pl.end());
  sort(pr.begin(), pr.end());
  vector<pair<ll,ll>> l, r;
  for (int i = 0; i < n * 4; i++) {
    if (!l.size() || l.back().first != pl[i].first) {
      l.push_back(pl[i]);
    }
    else {
      l.back().second += pl[i].second;
    }
    if (!r.size() || r.back().first != pr[i].first) {
      r.push_back(pr[i]);
    }
    else {
      r.back().second += pr[i].second;
    }
  }
  ll cnt = 0;
  for (int i = (int) l.size() - 1; i >= 0; i--) {
    ll t = l[i].second;
    if (i + 1 < (int) l.size()) {
      l[i].second += l[i + 1].second;
      l[i].second += cnt * (l[i + 1].first - l[i].first);
    }
    cnt += t;
  }
  cnt = 0;
  for (int i = 0; i < (int) r.size(); i++) {
    ll t = r[i].second;
    if (i - 1 >= 0) {
      r[i].second += r[i - 1].second;
      r[i].second += cnt * (r[i].first - r[i - 1].first);
    }
    cnt += t;
  }
  ll ans = 1e18;
  for (int i = 0; i < (int) l.size(); i++) {
    ans = min(ans, l[i].second + r[i].second);
  }
  cout << ans << '\n';
}