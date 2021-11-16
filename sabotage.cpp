#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-10;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  freopen("sabotage.in" , "r", stdin );
  freopen("sabotage.out", "w", stdout);
  int n; cin >> n;
  vector<double> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  auto check = [&](double x) {
    vector<double> t = a;
    double sum = 0;
    for (int i = 1; i <= n; i++) {
      t[i] = a[i] / x - 1;
      sum += t[i];
    }
    double mi = INT_MAX;
    vector<double> d(n + 1);
    for (int i = 1; i <= n - 1; i++) {
      d[i] = d[i - 1] + t[i];
      if (i >= 2 && sum - (d[i] - mi) <= EPS) {
        return true;
      }
      mi = min(mi, d[i]);
    }
    return false;
  };
  double l = 1, r = 10000, ans = -1;
  int cnt = 100;
  while (cnt--) {
    double x = (l + r) / 2;
    if (check(x)) {
      ans = x;
      r = x;
    }
    else l = x;
  }
  cout << fixed << setprecision(3) << ans << '\n';
}
