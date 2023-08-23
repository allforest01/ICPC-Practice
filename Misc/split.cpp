#include <bits/stdc++.h>
using namespace std;

#define int long long

void chmin(int &a, int b) {
  if (a > b) a = b;
}

void chmax(int &a, int b) {
  if (a < b) a = b;
}

int cal(vector<pair<int,int>> &v, int n) {
  vector<int> left_min(n), left_max(n), right_min(n), right_max(n);
  for (int i = 0; i < n; i++) {
    left_min[i] = left_max[i] = v[i].second;
    if (i > 0) {
      chmin(left_min[i], left_min[i - 1]);
      chmax(left_max[i], left_max[i - 1]);
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    right_min[i] = right_max[i] = v[i].second;
    if (i < n - 1) {
      chmin(right_min[i], right_min[i + 1]);
      chmax(right_max[i], right_max[i + 1]);
    }
  }
  int min_area = LLONG_MAX;
  for (int i = 0; i < n; i++) {
    if (v[i].second == v[i + 1].second) continue;
    int area  = (v[i].first     - v[0].first    ) * (left_max[i]      -      left_min[i]);
    if (i + 1 < n) {
      area += (v.back().first - v[i + 1].first) * (right_max[i + 1] - right_min[i + 1]);
    }
    chmin(min_area, area);
  }
  return min_area;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  freopen("split.in" , "r", stdin );
  freopen("split.out", "w", stdout);
  int n; cin >> n;
  vector<pair<int,int>> v(n);
  int min_x = LLONG_MAX, max_x = LLONG_MIN, min_y = LLONG_MAX, max_y = LLONG_MIN;
  for (auto &i : v) {
    cin >> i.first >> i.second;
    chmin(min_x, i.first);
    chmax(max_x, i.first);
    chmin(min_y, i.second);
    chmax(max_y, i.second);
  }
  int area = (max_x - min_x) * (max_y - min_y);
  sort(v.begin(), v.end());
  int ans = cal(v, n);
  for (auto &i : v) {
    swap(i.first, i.second);
  }
  sort(v.begin(), v.end());
  chmin(ans, cal(v, n));
  cout << area - ans << '\n';
}
