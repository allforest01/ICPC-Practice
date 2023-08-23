#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

long long a[N], b[N];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    b[i] = a[i] - i;
  }
  while (q--) {
    long long x; cin >> x;
    int i = lower_bound(b, b + n + 1, x) - b - 1;
    cout << x + i << '\n';
  }
}
