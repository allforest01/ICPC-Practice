#include <bits/stdc++.h>
using namespace std;

const int N = 100000;

int a[N + 5], ma[N + 5];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  a[0] = 0;
  a[1] = 1;
  for (int i = 0; i <= N; i++) {
    if (i * 2 <= N) a[i * 2] = a[i];
    if (i * 2 + 1 <= N) a[i * 2 + 1] = a[i] + a[i + 1];
  }
  for (int i = 1; i <= N; i++) {
    ma[i] = a[i];
    if (i > 0) ma[i] = max(ma[i], ma[i - 1]);
  }
  int q; cin >> q;
  while (q--) {
    int n; cin >> n;
    cout << ma[n] << '\n';
  }
}