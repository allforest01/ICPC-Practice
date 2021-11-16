#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void chmin(ll &a, ll b) {
  if (a > b) a = b;
}

void chmax(ll &a, ll b) {
  if (a < b) a = b;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<ll> a(n + 1), s(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    s[i] = a[i] + s[i - 1];
  }
  ll ans = LLONG_MIN;
  map<ll,ll> mem;
  for (int i = 1; i <= n; i++) {
    if (mem.count(a[i])) {
      chmax(ans, s[i] - mem[a[i]]);
      chmin(mem[a[i]], s[i - 1]);
    }
    else mem[a[i]] = s[i - 1];
  }
  cout << ans << '\n';
}
