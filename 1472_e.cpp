#include <bits/stdc++.h>
using namespace std;

void Main() {
  int n; cin >> n;
  vector<vector<int>> v;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    v.push_back({x, y, i});
    v.push_back({y, x, i});
  }
  sort(v.begin(), v.end(), [](vector<int> &a, vector<int> &b) {
    if (a[0] == b[0]) {
      return a[1] > b[1];
    }
    return a[0] < b[0];
  });
  vector<int> res(n + 1, -1);
  set<pair<int,int>> s;
  // cout << '\n';
  for (auto &i : v) {
    // cout << i[0] << ' ' << i[1] << ' ' << i[2] << '\n';
    auto it = s.upper_bound({-i[1], INT_MAX});
    if (it != s.end()) {
      res[i[2] + 1] = it->second + 1; 
      // res[it->second + 1]  = i[2] + 1;
      // cout << "> " << it->second << '\n';
    }
    s.insert(make_pair(-i[1], i[2]));
  }
  // cout << '\n';
  for (int i = 1; i <= n; i++) {
    cout << res[i] << ' ';
  }
  cout << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
