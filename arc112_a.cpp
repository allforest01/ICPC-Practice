#include <bits/stdc++.h>
using namespace std;

long long cal(long long n) {
  return n * (n + 1) / 2;
}

void Main() {
  int l, r;
  cin >> l >> r;
  // a = b + c
  int t = l * 2;
  long long ans = 0;
  if (r >= t) ans = cal(r - t + 1);
  cout << ans << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T --> 0) Main();
}
