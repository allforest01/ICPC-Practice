#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  long long ans = 1;
  for (int i = 1; i <= n; i++) {
    ans *= (a[i] - a[i - 1] + 1);
    ans %= MOD;
  }
  cout << ans << '\n';
}
