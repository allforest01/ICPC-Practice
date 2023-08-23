#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int w, l, n;
  cin >> w >> l >> n;
  vector<vector<pair<int,int>>> v(n), rev(n);
  for (int i = 0; i < n; i++) {
    v[i].resize(l);
    rev[i].resize(l);
    int mif = INT_MAX, mis = INT_MAX;
    for (int j = 0; j < l; j++) {
      cin >> v[i][j].first;
      mif = min(mif, v[i][j].first);
    }
    for (int j = 0; j < l; j++) {
      cin >> v[i][j].second;
      mis = min(mis, v[i][j].second);
    }
    for (int j = 0; j < l; j++) {
      int mid = w - v[i][j].first - v[i][j].second;
      rev[i][l - j - 1] = make_pair(v[i][j].second - mis, mid);
      v[i][j] = make_pair(v[i][j].first - mif, mid);
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    bool flag = false;
    for (int j = 0; j < i; j++) {
      if (v[i] == v[j] || v[i] == rev[j]) {
        flag = true;
        break;
      }
    }
    if (!flag) ans++;
  }
  cout << ans << '\n';
}
