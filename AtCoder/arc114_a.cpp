#include <bits/stdc++.h>
using namespace std;

#define bit(x, k) (((x) >> (k)) & 1)

int main() {
  cin.tie(0)->sync_with_stdio(0);
  vector<long long> prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
  int n; cin >> n;
  vector<long long> v(n);
  for (auto &i : v) cin >> i;
  long long ans = LLONG_MAX;
  for (int mask = 1; mask < (1 << prime.size()); mask++) {
    long long t = 1;
    for (int i = 0; i < prime.size(); i++) {
      if (bit(mask, i)) t *= prime[i];
    }
    bool flag = 0;
    for (auto &i : v) {
      if (__gcd(i, t) == 1) {
        flag = 1;
        break;
      }
    }
    if (!flag) ans = min(ans, t);
  }
  cout << ans << '\n';
}
