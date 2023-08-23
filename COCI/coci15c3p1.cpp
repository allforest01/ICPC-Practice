#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll Pow(ll a, ll b) {
  if (b == 0) return 1;
  ll t = Pow(a, b / 2);
  t *= t;
  if (b % 2) return t * a;
  else return t;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    ans += Pow(stoll(s.substr(0, s.size() - 1)), s.back() - '0');
  }
  cout << ans << '\n';
}
