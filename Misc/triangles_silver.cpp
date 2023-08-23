#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 1e9 + 7;

int mod(int x) {
  return (x % MOD + MOD) % MOD;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  freopen("triangles.in" , "r", stdin );
  freopen("triangles.out", "w", stdout);
  int n; cin >> n;
  vector<pair<int,int>> v(n);
  map<int,vector<int>> map_x, map_y;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    v[i] = make_pair(x, y);
    map_x[x].push_back(y);
    map_y[y].push_back(x);
  }
  map<int,vector<int>> x_lf, x_ri, y_lf, y_ri;
  for (auto &i : map_x) {
    vector<int> &v = i.second;
    vector<int> &l = x_lf[i.first];
    vector<int> &r = x_ri[i.first];
    sort(v.begin(), v.end());
    int v_sz = v.size();
    l.resize(v_sz);
    r.resize(v_sz);
    for (int j = 0; j < v_sz; j++) {
      l[j] = v[j] - v[0];
      if (j > 0) l[j] = mod(l[j] + l[j - 1]);
    }
    for (int j = v_sz - 1; j >= 0; j--) {
      r[j] = v[v_sz - 1] - v[j];
      if (j < v_sz - 1) r[j] = mod(r[j] + r[j + 1]);
    }
  }
  for (auto &i : map_y) {
    vector<int> &v = i.second;
    vector<int> &l = y_lf[i.first];
    vector<int> &r = y_ri[i.first];
    sort(v.begin(), v.end());
    int v_sz = v.size();
    l.resize(v_sz);
    r.resize(v_sz);
    for (int j = 0; j < v_sz; j++) {
      l[j] = v[j] - v[0];
      if (j > 0) l[j] = mod(l[j] + l[j - 1]);
    }
    for (int j = v_sz - 1; j >= 0; j--) {
      r[j] = v[v_sz - 1] - v[j];
      if (j < v_sz - 1) r[j] = mod(r[j] + r[j + 1]);
    }
  }
  int ans = 0;
  for (auto &i : v) {
    int x = i.first, y = i.second;
    int px = lower_bound(map_x[x].begin(), map_x[x].end(), y) - map_x[x].begin();
    int py = lower_bound(map_y[y].begin(), map_y[y].end(), x) - map_y[y].begin();
    int x_sz = map_x[x].size(), y_sz = map_y[y].size();
    int sum_x_lf = (x_ri[x][0] - x_ri[x][px]) - (map_x[x].back() - y) * px;
    int sum_x_ri = (x_lf[x].back() - x_lf[x][px]) - (y - map_x[x][0]) * (x_sz - px - 1);
    int sum_y_lf = (y_ri[y][0] - y_ri[y][py]) - (map_y[y].back() - x) * py;
    int sum_y_ri = (y_lf[y].back() - y_lf[y][py]) - (x - map_y[y][0]) * (y_sz - py - 1);
    ans += mod(mod(sum_x_lf + sum_x_ri) * mod(sum_y_lf + sum_y_ri));
    ans %= MOD;
  }
  cout << ans << '\n';
}
