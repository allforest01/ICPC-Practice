#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<int> neg, pos;
  bool zero = 0;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    if (x < 0) neg.push_back(x);
    if (x > 0) pos.push_back(x);
    if (x == 0) zero = 1;
  }
  sort(neg.begin(), neg.end());
  sort(pos.begin(), pos.end());
  if (!pos.size()) {
    if (zero) cout << 0 << '\n';
    else cout << neg.back() << '\n';
  }
  else {
    long long ans = 1;
    for (auto &i : pos) ans *= i;
    for (int i = 0; i + 1 < (int) neg.size(); i += 2) {
      ans *= neg[i] * neg[i + 1];
    }
    cout << ans << '\n';
  }
}
