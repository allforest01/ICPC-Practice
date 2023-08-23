#include <bits/stdc++.h>
using namespace std;

int Main() {
  int n; cin >> n;
  vector<int> a(n), b(n);
  for (auto &i : a) cin >> i;
  for (auto &i : b) cin >> i;
  vector<pair<int,int>> res;
  for (int i = 0; i < n; i++) {
    while (a[i] > b[i]) {
      bool flag = 0;
      for (int j = 0; j < n; j++) {
        while (a[i] > b[i] && a[j] < b[j]) {
          a[i]--;
          a[j]++;
          res.push_back(make_pair(i, j));
          flag = 1;
        }
      }
      if (!flag) {
        cout << -1 << '\n';
        return 0;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (a[i] != b[i]) {
      cout << -1 << '\n';
      return 0;
    }
  }
  cout << res.size() << '\n';
  for (auto &i : res) {
    cout << i.first + 1 << ' ' << i.second + 1 << '\n';
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
