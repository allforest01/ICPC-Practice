#include <bits/stdc++.h>
using namespace std;

void Main() {
  long long s, n, k;
  cin >> s >> n >> k;
  cout << ((k == s || k + 1 <= ((s - n) == 0 ? 2e9 : n / (s - n))) ? "YES" : "NO") << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}