#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define ii pair<int,int>
#define fi first
#define sc second

void Main() {
  int n, l, r;
  cin >> n >> l >> r;
  map<int, ii> m;
  for (int i = 1; i <= n; i++) {
    int c; cin >> c;
    if (i <= l) m[c].fi++;
    else m[c].sc++;
  }
  int sl = 0, dl = 0, sr = 0, dr = 0;
  for (auto &i : m) {
    int l = i.sc.fi, r = i.sc.sc;
    int t = abs(l - r);
    if (l > r) {
      sl += t / 2;
      dl += t % 2;
    }
    else {
      sr += t / 2;
      dr += t % 2;
    }
  }
  int ans = 0, flg = 1;
  while (flg) {
    flg = 0;
    while (sl * 2 + dl > sr * 2 + dr && sl) {
      sl--;
      ans++;
      flg = 1;
    }
    while (sl * 2 + dl < sr * 2 + dr && sr) {
      sr--;
      ans++;
      flg = 1;
    }
  }
  while (sl && sr) {
    sl--;
    sr--;
    ans += 2;
  }
  int tl = sl * 2 + dl, tr = sr * 2 + dr;
  ans += (tl + tr) / 2 + abs(tl - tr) / 2;
  cout << ans << endl;
}

signed main() {
  // freopen("in" , "r", stdin );
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
