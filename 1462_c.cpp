#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  vector<string> res(51);
  res[1] = "1";
  for (int i = 2; i <= 45; i++) {
    res[i] = res[i - 1];
    if (res[i][0] - '0' < 10 - res[i].size()) {
      res[i][0]++;
    }
    else {
      res[i] = '1' + res[i];
    }
  }
  int T; cin >> T;
  while (T--) {
    int x; cin >> x;
    if (res[x].size()) cout << res[x] << '\n';
    else cout << -1 << '\n';
  }
}
