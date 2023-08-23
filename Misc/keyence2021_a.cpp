#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<long long> a(n + 1), b(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] = max(a[i], a[i - 1]);
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    b[i] *= a[i];
    b[i] = max(b[i], b[i - 1]);
    cout << b[i] << '\n';
  }
}
