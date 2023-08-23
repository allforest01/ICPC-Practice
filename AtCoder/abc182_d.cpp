#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<long long> a(n), ma(n);
  long long ans = 0, pos = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (i > 0) {
      a[i] += a[i - 1];
    }
    ma[i] = a[i];
    if (i > 0) {
      ma[i] = max(ma[i], ma[i - 1]);
    }
    ans = max(ans, pos + ma[i]);
    pos += a[i];
  }
  cout << ans << '\n';
}
