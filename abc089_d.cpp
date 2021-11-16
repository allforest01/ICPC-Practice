#include <bits/stdc++.h>
using namespace std;

const int N = 300 * 300 + 1;

int x[N], y[N], sum[N], brk[N];

int dist(int x, int y, int i, int j) {
  return abs(x - i) + abs(y - j);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m, d;
  cin >> n >> m >> d;
  for (int i = 1; i <= n; i++)
  for (int j = 1; j <= m; j++) {
    int t; cin >> t;
    x[t] = i;
    y[t] = j;
  }
  for (int i = 1; i + d < N; i++) {
    int j = i + d;
    int t = dist(x[i], y[i], x[j], y[j]);
    brk[j] = brk[i];
    if (x[j] == 0) brk[j]++;
    else sum[j] = sum[i] + t;
  }
  int q; cin >> q;
  while (q--) {
    int ql, qr;
    cin >> ql >> qr;
    int l = ql, r = qr, res = -1;
    while (l <= r) {
      int m = (l + r) / 2;
      if (brk[m] > brk[ql]) {
        r = m - 1;
      }
      else {
        l = m + 1;
        res = m;
      }
    }
    cout << sum[res] - sum[ql] << '\n';
  }
}
