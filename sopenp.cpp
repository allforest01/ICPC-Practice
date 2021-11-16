#include <bits/stdc++.h>
using namespace std;

const int N = 2000005;

int a[N];

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, l, r;
  cin >> n >> l >> r;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  map<int,int> cl, cr;
  int pl = 1, pr = 1;
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    cl[a[i]]++; cr[a[i]]++;
    while (pr < i && (int) cr.size() > r) {
      if (--cr[a[pr]] == 0) cr.erase(a[pr]);
      pr++;
    }
    while (pl <= i && (int) cl.size() >= l) {
      if (--cl[a[pl]] == 0) cl.erase(a[pl]);
      pl++;
    }
    if ((int) cr.size() <= r && (int) cl.size() < l) {
      ans += pl - pr;
    }
  }
  cout << ans << '\n';
}
