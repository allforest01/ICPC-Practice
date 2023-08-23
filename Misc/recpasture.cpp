#include <bits/stdc++.h>
using namespace std;

#define int long long

int grid[2501][2501];

int gsum(int x1, int y1, int x2, int y2) {
  return grid[x2][y2] - grid[x1 - 1][y2] - grid[x2][y1 - 1] + grid[x1 - 1][y1 - 1];
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<pair<int,int>> v(n);
  for (auto &i : v) {
    cin >> i.first >> i.second;
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < n; i++) {
    v[i].first = i + 1;
  }
  sort(v.begin(), v.end(), [](pair<int,int> &a, pair<int,int> &b) {
    return a.second < b.second;
  });
  for (int i = 0; i < n; i++) {
    v[i].second = i + 1;
  }
  for (int i = 0; i < n; i++) {
    grid[v[i].first][v[i].second] = 1;
  }
  for (int i = 1; i <= n; i++)
  for (int j = 1; j <= n; j++) {
    grid[i][j] += grid[i - 1][j] + grid[i][j - 1] - grid[i - 1][j - 1];
  }
  int ans = 0;
  for (int i = 0; i < n; i++)
  for (int j = i; j < n; j++) {
    int ix, iy, jx, jy;
    tie(ix, iy) = v[i];
    tie(jx, jy) = v[j];
    int x_min = min(ix, jx);
    int x_max = max(ix, jx);
    ans += gsum(1, iy, x_min, jy) * gsum(x_max, iy, n, jy);
  }
  cout << ans + 1 << '\n';
}
