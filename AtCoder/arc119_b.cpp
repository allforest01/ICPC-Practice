#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  string a, b;
  cin >> a >> b;
  vector<int> va, vb;
  for (int i = 0; i < n; i++) {
    if (a[i] == '0') va.push_back(i);
  }
  for (int i = 0; i < n; i++) {
    if (b[i] == '0') vb.push_back(i);
  }
  if (va.size() != vb.size()) {
    cout << -1 << '\n';
    return 0;
  }
  int ans = 0;
  for (int i = 0; i < (int) va.size(); i++) {
    ans += va[i] != vb[i];
  }
  cout << ans << '\n';
}
