#include <bits/stdc++.h>
using namespace std;

#define taskname "INTEQN"

void ioset() {
  cin.tie(0)->sync_with_stdio(0);
  if (fopen(taskname".INP", "r")) {
    freopen(taskname".INP", "r", stdin );
    freopen(taskname".OUT", "w", stdout);
  }
}

typedef long long ll;
typedef pair<ll,ll> pll;

#define X first
#define Y second

ll gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

pll extEuclid(ll a, ll b) {
  if (b == 0) return {1, 0};
  pll t = extEuclid(b, a % b);
  return {t.Y, t.X - a / b * t.Y};
}

void solve() {
  ll a, b, c;
  cin >> a >> b >> c;
  a /= c; b /= c;
  pll t = extEuclid(a, b);
  cout << t.X << ' ' << t.Y << '\n';
}

signed main() {
  ioset();
  int T; cin >> T;
  while (T--) solve();
}
