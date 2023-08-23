#include <bits/stdc++.h>
using namespace std;

void chmax(int &a, int b) {
  if (a < b) a = b;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<int> a(n + 2), l(n + 2), r(n + 2);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 2; i <= n; i++) {
    l[i] = max(a[i] - a[i - 1], l[i - 1]);
  }
  for (int i = n - 1; i >= 1; i--) {
    r[i] = max(a[i + 1] - a[i], r[i + 1]);
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int t = 0;
    if (i >= 2 && i <= n - 1) t = a[i + 1] - a[i - 1];
    chmax(t, l[i - 1]);
    chmax(t, r[i + 1]);
    chmax(ans, t);
  }
  cout << ans << '\n';
}
