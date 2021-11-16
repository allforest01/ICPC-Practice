#include <bits/stdc++.h>
using namespace std;

int n, d, m;
deque<pair<int,int>> dq;
vector<vector<int>> res;

bool check(int x) {
  res.assign(n + 1, vector<int>());
  int p = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= x; j++) {
      int t = dq[p].first;
      if (t > i) break;
      if (t + d >= i) {
        res[i].push_back(dq[p].second);
        p++;
      }
      else return false;
      if (p == m) return true;
    }
  }
  return false;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> d >> m;
  dq.resize(m);
  for (int i = 0; i < m; i++) {
    cin >> dq[i].first;
    dq[i].second = i + 1;
  }
  sort(dq.begin(), dq.end());
  int l = 1, r = m, ans = -1;
  vector<vector<int>> sav;
  while (l <= r) {
    int x = (l + r) / 2;
    if (check(x)) {
      ans = x;
      sav = res;
      r = x - 1;
    }
    else l = x + 1;
  }
  cout << ans << '\n';
  for (int i = 1; i <= n; i++) {
    for (auto &j : sav[i]) cout << j << ' ';
    cout << 0 << '\n';
  }
}
