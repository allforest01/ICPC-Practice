#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  ll n, s;
  cin >> n >> s;
  cout << n * (n + 1) / 2 - s << '\n';
}
