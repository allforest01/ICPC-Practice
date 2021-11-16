#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

long long a[N], b[N], odd[N], even[N];

long long get(long long* a, long long l, long long r) {
  return a[r] - a[l - 1];
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) {
    odd[i]  =  odd[i - 1];
    even[i] = even[i - 1];
    if (i + 1 <= n) {
      long long diff = abs(a[i] - a[i + 1]);
      if (i % 2) odd[i] += diff;
      else even[i] += diff;
    }
  }
  long long ans = 1e18;
  for (int i = 1; i <= m; i++) {
    long long p = upper_bound(a + 1, a + n + 1, b[i]) - a, cal;
    if (p % 2 == 0) {
      cal = get(odd, 1LL, p - 2) + abs(a[p - 1] - b[i]) + get(even, p, n);
    }
    else {
      cal = get(odd, 1LL, p - 1) + abs(a[p] - b[i]) + get(even, p + 1, n);
    }
    ans = min(ans, cal);
  }
  cout << ans << '\n';
}
