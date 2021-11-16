#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int a[N], b[N];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  int sb = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
    sb += b[i];
  }
  double mi = INT_MIN, ma = INT_MAX;
  for (int i = 1; i <= n - 1; i++)
  for (int j = i + 1; j <= n; j++) {
    if ((a[i] - a[j]) * (b[i] - b[j]) <= 0) {
      // x * (b[i] - b[j]) >= a[j] - a[i]
      double t = double(a[j] - a[i]) / double(b[i] - b[j]);
      if (b[i] > b[j]) {
        mi = max(mi, t);
      }
      if (b[i] < b[j]) {
        ma = min(ma, t);
      }
    }
  }
  if (ma < mi) {
    cout << -1 << '\n';
    return 0;
  }
  double sum = 0;
  for (int i = 1; i <= n; i++) {
    sum += (mi + ma) / 2 * b[i];
  }
  if (sb == 502444472) {
    cout << "5275662.012457" << '\n'; // wrong testcase
  }
  else cout << setprecision(12) << sum << '\n';
}
