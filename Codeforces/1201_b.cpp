#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  long long sum = 0, ma = 0;
  for (int i = 0; i < n; i++) {
    long long x; cin >> x;
    sum += x;
    ma = max(ma, x);
  }
  if (sum % 2 == 0 && ma <= sum - ma) {
    cout << "YES" << '\n';
  }
  else {
    cout << "NO" << '\n';
  }
}
