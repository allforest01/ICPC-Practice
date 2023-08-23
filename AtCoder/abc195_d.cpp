#include <bits/stdc++.h>
using namespace std;

void chmax(pair<int,int> &a, pair<int,int> b) {
  if (a.second == b.second) {
    if (a.first > b.first) a = b;
  }
  else {
    if (a.second < b.second) a = b;
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m, q;
  cin >> n >> m >> q;
  vector<pair<int,int>> a(n);
  for (auto &i : a) {
    cin >> i.first >> i.second;
  }
  sort(a.begin(), a.end(), greater<pair<int,int>>());
  vector<int> b(m);
  for (auto &i : b) {
    cin >> i;
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    l--; r--;
    vector<int> c;
    for (int i = 0; i < m; i++) {
      if (i < l || i > r) c.push_back(b[i]);
    }
    sort(c.begin(), c.end());
    int ans = 0;
    vector<int> d(n);
    for (auto &i : c) {
      pair<int,int> sav = make_pair(INT_MAX, 0);
      for (int j = 0; j < n; j++) {
        if (i >= a[j].first && !d[j]) {
          chmax(sav, a[j]);
        }
      }
      ans += sav.second;
      for (int j = 0; j < n; j++) {
        if (sav == a[j] && !d[j]) {
          d[j] = 1;
          break;
        }
      }
    }
    cout << ans << '\n';
  }
}
