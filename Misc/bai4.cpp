#define task "buildcol"

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 100005;

int n; ll m;
int a[N], b[N], l[N], r[N];

bool check(int x) {
  for (int i = 1; i <= n; i++) {
    b[i] = a[i] >= x ? a[i] : x;
  }
  for (int i = 1; i <= n; i++) {
    l[i] = i - 1;
    while (l[i] >= 1 && b[l[i]] >= b[i]) l[i] = l[l[i]];
  }
  for (int i = n; i >= 1; i--) {
    r[i] = i + 1;
    while (r[i] <= n && b[r[i]] >= b[i]) r[i] = r[r[i]];
  }
  ll sum = 0;
  for (int i = 1; i <= n; i++) {
    if (l[i] >= 1 && r[i] <= n) {
      sum += (ll) min(b[l[i]], b[r[i]]) * (r[i] - l[i]);
    }
  }
  return sum >= m;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  if (fopen(task".INP", "r")) {
    freopen(task".INP", "r", stdin );
    freopen(task".OUT", "w", stdout);
  }
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int l = 0, r = 2e9, ans = -1;
  while (l <= r) {
    int x = (l + r) / 2;
    if (check(x)) {
      ans = x;
      r = x + 1;
    }
    else {
      l = x - 1;
    }
  }
  cout << ans << '\n'l
}
