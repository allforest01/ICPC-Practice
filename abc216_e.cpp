#include <bits/stdc++.h>
using namespace std;

#define int long long

int sum(int n) {
  return n * (n + 1) / 2;
}

int sum(int l, int r) {
  return sum(r) - (l > 0 ? sum(l - 1) : 0);
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a.begin() + 1, a.end());
  int ans = 0;
  for (int i = n; i >= 1; i--) {
    int l = n - i + 1;
    int d = (a[i] - a[i - 1]) * l;
    if (k >= d) {
      ans += sum(a[i - 1] + 1, a[i]) * l;
      k -= d;
    }
    else {
      int t = k / l;
      ans += sum(a[i] - t + 1, a[i]) * l;
      ans += (a[i] - t) * (k % l);
      break;
    }
  }
  cout << ans << '\n';
}
