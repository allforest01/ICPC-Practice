#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  vector<vector<int>> v(n);
  for (auto &i : v) {
    i.resize(k);
    for (auto &j : i) cin >> j;
    sort(i.begin(), i.end());
  }
  multiset<pair<int,int>> ms_mi, ms_ma, rem_mi, rem_ma;
  for (int i = 0; i < n; i++) {
    int cur_mi = v[i].front(), cur_ma = v[i].back();
    if (ms_mi.size()) {
      int val = ms_mi.begin()->first;
      if (val > cur_ma) continue;
    }
    while (ms_ma.size()) {
      int val = ms_ma.begin()->first;
      int pos = ms_ma.begin()->second;
      if (val < cur_mi) {
        ms_mi.erase(make_pair(v[pos].front(), pos));
        ms_ma.erase(ms_ma.begin());
      }
      else break;
    }
    ms_mi.insert(make_pair(cur_mi, i));
    ms_ma.insert(make_pair(cur_ma, i));
    cout << ms_mi.size() << '\n';
  }
}
