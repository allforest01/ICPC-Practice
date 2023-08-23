#include <bits/stdc++.h>
using namespace std;

pair<int, int> move(int x, int y, char c) {
  if (c == 'N') y++;
  if (c == 'S') y--;
  if (c == 'E') x++;
  if (c == 'W') x--;
  return make_pair(x, y);
}

int main() {
  freopen("mowing.in" , "r", stdin );
  freopen("mowing.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  map<pair<int, int>, int> grid;
  int x = 0, y = 0, time = 0, ans = INT_MAX;
  grid[make_pair(x, y)] = time;
  for (int i = 0; i < n; i++) {
    char c; int t;
    cin >> c >> t;
    for (int j = 1; j <= t; j++) {
      time++;
      auto nxt_pos = move(x, y, c);
      if (grid.count(nxt_pos)) {
        ans = min(ans, time - grid[nxt_pos]);
      }
      grid[nxt_pos] = time;
      tie(x, y) = nxt_pos;
    }
  }
  if (ans == INT_MAX) ans = -1;
  cout << ans << '\n';
}
