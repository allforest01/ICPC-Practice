#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int a[N];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  freopen("haybales.in" , "r", stdin );
  freopen("haybales.out", "w", stdout);
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  a[0] = INT_MIN; a[n + 1] = INT_MAX;
  while (q--) {
    int l, r;
    cin >> l >> r;
    int pl = lower_bound(a + 1, a + n + 1, l) - a;
    int pr = upper_bound(a + 1, a + n + 1, r) - a;
    cout << pr - pl << '\n';
  }
}
