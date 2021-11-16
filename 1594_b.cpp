#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

void Main() {
  long long n, k;
  cin >> n >> k;
  long long p = 1, ans = 0;
  while (k > 0) {
    int m = k % 2;
    (ans += p * m) %= MOD;
    k /= 2;
    (p *= n) %= MOD;
  }
  cout << ans << '\n';
}

int main() {
  int T; cin >> T;
  while (T--) Main();
}