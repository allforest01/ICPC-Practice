#include <bits/stdc++.h>
using namespace std;

const int N = 105;

set<pair<int,int>> road[N][N];
int color[N][N];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  freopen("countcross.in" , "r", stdin );
  freopen("countcross.out", "w", stdout);
  int n, k, r;
  cin >> n >> k >> r;
  for (int i = 0; i < r; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    road[x1][y1].insert(make_pair(x2, y2));
    road[x2][y2].insert(make_pair(x1, y1));
  }
  int col = 0;
  for (int i = 1; i <= n; i++)
  for (int j = 1; j <= n; j++) {
    if (!color[i][j]) {
      col++;
      queue<pair<int,int>> q;
      q.push(make_pair(i, j));
      while (q.size()) {
        int x, y;
        tie(x, y) = q.front(); q.pop();
        if (color[x][y]) continue;
        color[x][y] = col;
        for (int k = 0; k < 4; k++) {
          int nx = x + dx[k], ny = y + dy[k];
          if (nx < 1 || nx > n || ny < 1 || ny > n) continue;
          if (road[x][y].count(make_pair(nx, ny))) continue;
          q.push(make_pair(nx, ny));
        }
      }
    }
  }
  vector<pair<int,int>> cows(k);
  for (auto &i : cows) {
    cin >> i.first >> i.second;
  }
  int ans = 0;
  for (int i = 0; i + 1 < k; i++)
  for (int j = i + 1; j < k; j++) {
    int i_x, i_y, j_x, j_y;
    tie(i_x, i_y) = cows[i];
    tie(j_x, j_y) = cows[j];
    if (color[i_x][i_y] != color[j_x][j_y]) {
      ans++;
    }
  }
  cout << ans << '\n';
}
