#include <bits/stdc++.h>
using namespace std;

void Main() {
  int n; cin >> n;
  vector<long long> a(n);
  for (auto &i : a) cin >> i;
  long long ans = 0;
  for (int i = 1; i < n; i++) {
    ans = max(ans, a[i - 1] * a[i]);
  }
  cout << ans << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
