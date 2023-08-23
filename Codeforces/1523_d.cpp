#include <bits/stdc++.h>
using namespace std;

#define ii pair<int,int>
#define fi first
#define sc second

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int sum = 0;
  vector<ii> a(4);
  while (1) {
    sum = 0;
    for (int i = 1; i <= 3; i++) {
      cin >> a[i].fi >> a[i].sc;
      sum += a[i].fi +  a[i].sc;
      if (a[i].fi > a[i].sc) {
        swap(a[i].fi, a[i].sc);
      }
    }
    if (sum == 0) break;
    sort(a.begin() + 1, a.end(), [](ii a, ii b) {
      return a.sc < b.sc;
    });
    int ans = 0, ma = 0;
    for (int i = 3; i >= 1; i--) {
      ma = max(ma, a[i].fi);
      ans += ma * (a[i].sc - a[i - 1].sc);
    }
    cout << ans << '\n';
  }
}