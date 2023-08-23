#include <bits/stdc++.h>
using namespace std;

int dist(int x, int y, int n) {
  if (y >= x) return y - x;
  return y + n - x;
}

int main() {
  freopen("cbarn.in" , "r", stdin );
  freopen("cbarn.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int ans = INT_MAX;
  for (int j = 1; j <= n; j++) {
    int cal = 0;
    for (int i = 1; i <= n; i++) {
      cal += a[i] * dist(j, i, n);
    }
    ans = min(ans, cal);
  }
  cout << ans << '\n';
}
