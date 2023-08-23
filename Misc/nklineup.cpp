#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, q;
  cin >> n >> q;
  vector<array<int,20>> sp_max(n + 1), sp_min(n + 1);
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    sp_max[i][0] = sp_min[i][0] = x;
  }
  for (int j = 1; j < 20; j++)
  for (int i = 1; i + (1 << j) - 1 <= n; i++) {
    sp_max[i][j] = max(sp_max[i][j - 1], sp_max[i + (1 << (j - 1))][j - 1]);
    sp_min[i][j] = min(sp_min[i][j - 1], sp_min[i + (1 << (j - 1))][j - 1]);
  }
  auto getMax = [&sp_max](int l, int r) {
    int d = 0;
    while ((1 << (d + 1)) <= r - l + 1) d++;
    return max(sp_max[l][d], sp_max[r - (1 << d) + 1][d]);
  };
  auto getMin = [&sp_min](int l, int r) {
    int d = 0;
    while ((1 << (d + 1)) <= r - l + 1) d++;
    return min(sp_min[l][d], sp_min[r - (1 << d) + 1][d]);
  };
  while (q--) {
    int u, v;
    cin >> u >> v;
    cout << getMax(u, v) - getMin(u, v) << '\n';
  }
}
