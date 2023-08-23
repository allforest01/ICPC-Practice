#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  // cin.tie(0)->sync_with_stdio(0);
  int k, n, m;
  cin >> k >> n >> m;
  vector<int> a(k), b(k), r(k);
  vector<pair<int,int>> v;
  int rm = m;
  for (int i = 0; i < k; i++) {
    cin >> a[i];
    b[i] = (a[i] * m) / n;
    r[i] = (a[i] * m) % n;
    v.emplace_back(r[i], i);
    rm -= b[i];
  }
  sort(v.begin(), v.end(), greater<pair<int,int>>());
  for (int i = 0; i < rm; i++) {
    b[v[i].second]++;
  }
  for (int i = 0; i < k; i++) {
    cout << b[i] << ' ';
  }
  cout << '\n';
}
