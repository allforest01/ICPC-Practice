#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 100005;

int a[N], b[N];

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  freopen("in" , "r", stdin );
  freopen("out", "w", stdout);
  int n, m, q;
  cin >> n >> m >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
  }
  int sum_a = 0;
  for (int i = 1; i <= n; i++) {
    if (i % 2) sum_a += a[i];
    else sum_a -= a[i];
  }
  int sum_b = 0;
  for (int i = 1; i <= n; i++) {
    if (i % 2) sum_b += b[i];
    else sum_b -= b[i];
    cerr << sum_b << ' ';
  }
  cerr << '\n';
  set<int> s;
  s.insert(sum_b);
  cerr << sum_b << ' ';
  for (int i = n + 1; i <= m; i++) {
    sum_b -= b[i - n];
    sum_b = - sum_b;
    if (n % 2) sum_b += b[i];
    else sum_b -= b[i];
    s.insert(sum_b);
    cerr << sum_b << ' ';
  }
  cerr << '\n';
  for (int i = 0; i <= q; i++) {
    if (i) {
      int l, r, t;
      cin >> l >> r >> t;
      if ((r - l + 1) % 2) {
        if (l % 2) sum_a += t;
        else sum_a -= t;
      }
    }
    auto it = s.lower_bound(sum_a);
    int ans = LLONG_MAX;
    if (it != s.end()  ) ans = min(ans, *it - sum_a);
    if (it != s.begin()) ans = min(ans, sum_a - *prev(it));
    cerr << "sum_a = " << sum_a << '\n';
    cout << ans << '\n';
  }
}
