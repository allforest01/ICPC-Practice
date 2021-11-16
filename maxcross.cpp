#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  freopen("maxcross.in" , "r", stdin );
  freopen("maxcross.out", "w", stdout);
  int n, k, b;
  cin >> n >> k >> b;
  vector<int> a(n + 1, 1);
  a[0] = 0;
  for (int i = 0; i < b; i++) {
    int x; cin >> x;
    a[x] = 0;
  }
  for (int i = 1; i <= n; i++) {
    a[i] += a[i - 1];
  }
  int ans = INT_MAX;
  for (int i = 1; i + k - 1 <= n; i++) {
    int s = a[i + k - 1] - a[i - 1];
    ans = min(ans, k - s);
  }
  cout << ans << '\n';
}
