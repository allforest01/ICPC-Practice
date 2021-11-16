#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  long long n; cin >> n;
  long long ans = LLONG_MAX;
  for (long long i = 0; i <= 61; i++) {
    long long t = (1LL << i);
    ans = min(ans, n / t + i + n % t);
  }
  cout << ans << '\n';
}
