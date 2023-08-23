#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int a[N];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  freopen("angry.in" , "r", stdin );
  freopen("angry.out", "w", stdout);
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  auto lf = [&](int i) {
    int rad = 1, flag = 1, l = i, p = i;
    while (flag) {
      flag = 0;
      while (l > 1 && a[l - 1] >= a[p] - rad) {
        l--;
        flag = 1;
      }
      rad++;
      p = l;
    }
    return l;
  };
  auto rg = [&](int i) {
    int rad = 1, flag = 1, r = i, p = i;
    while (flag) {
      flag = 0;
      while (r < n && a[r + 1] <= a[p] + rad) {
        r++;
        flag = 1;
      }
      rad++;
      p = r;
    }
    return r;
  };
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, rg(i) - lf(i) + 1);
  }
  cout << ans << '\n';
}
