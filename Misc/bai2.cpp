#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int x; cin >> x;
  vector<int> v;
  while (x != 0) {
    v.push_back(x);
    for (int i = 1; i < 12; i++) {
      cin >> x;
      v.push_back(x);
    }
    sort(v.begin(), v.end());
    bool flag = 0;
    for (int i = 0; i < 12; i++) {
      if (v[i] != v[i / 4 * 4]) {
        cout << "no" << '\n';
        flag = 1;
        break;
      }
    }
    if (!flag) cout << "yes" << '\n';
    v.clear();
    cin >> x;
  }
}
