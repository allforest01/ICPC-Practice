#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<pair<int,int>> v;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    v.push_back(make_pair(x    , -1));
    v.push_back(make_pair(y + 1,  1));
  }
  sort(v.begin(), v.end());
  vector<int> res(n + 1);
  int cnt = 0, p = -1;
  for (auto &i : v) {
    if (p != -1) res[cnt] += i.first - p;
    cnt -= i.second;
    p = i.first;
  }
  for (int i = 1; i <= n; i++) {
    cout << res[i] << ' ';
  }
  cout << '\n';
}
