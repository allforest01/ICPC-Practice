#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;

long long a[N], sum[N];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    sum[i] = a[i] += sum[i - 1];
  }
  int q; cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << sum[r + 1] - sum[l] << '\n';
  }
}
