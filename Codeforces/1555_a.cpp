#include <bits/stdc++.h>
using namespace std;

void Main() {
  long long n; cin >> n;
  if (n <= 6) cout << 15 << '\n';
  else cout << (n + 1) / 2 * 5 << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
