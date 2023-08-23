#include <bits/stdc++.h>
using namespace std;

long long sum(long long n) {
  return n * (n + 1) / 2;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  long long n; cin >> n;
  set<long long> d;
  int ans = 0;
  for (long long i = 1; sum(i) <= n; i++) {
    if ((n - sum(i)) % i == 0) {
      ans += 2;
    }
  }
  cout << ans << '\n';
}
