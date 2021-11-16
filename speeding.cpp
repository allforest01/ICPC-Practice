#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int a[N];

int main() {
  freopen("speeding.in" , "r", stdin );
  freopen("speeding.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  int sum = 1;
  for (int i = 0; i < n; i++) {
    int len, spd;
    cin >> len >> spd;
    for (int i = sum; i < sum + len; i++) {
      a[i] = spd;
    }
    sum += len;
  }
  int ans = 0;
  sum = 1;
  for (int i = 0; i < m; i++) {
    int len, spd;
    cin >> len >> spd;
    for (int i = sum; i < sum + len; i++) {
      ans = max(ans, spd - a[i]);
    }
    sum += len;
  }
  cout << ans << '\n';
}
