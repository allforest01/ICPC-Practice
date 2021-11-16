#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  long long n; cin >> n;
  map<long long,bool> m;
  long long ans = n;
  for (long long i = 2; i * i <= n; i++) {
    if (m.count(i)) continue;
    long long t = i * i;
    while (t <= n) {
      ans--;
      m[t] = true;
      t *= i;
    }
  }
  cout << ans << '\n';
}
