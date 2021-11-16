#include <bits/stdc++.h>
using namespace std;

const int N = 105;

char a[N][N];
int dis[N][N];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  queue<pair<int,int>> q;
  for (int i = 1; i <= n; i++)
  for (int j = 1; j <= m; j++) {
    cin >> a[i][j];
    if (a[i][j] == 'B') {
      q.push({i, j});
      dis[i][j] = 1;
    }
  }
  while (q.size()) {
    int x, y;
    tie(x, y) = q.front(); q.pop();
    if (a[x][y] == 'C') {
      cout << dis[x][y] - 1 << '\n';
      return 0;
    }
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i], ny = y + dy[i];
      if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
      if (a[nx][ny] == '*' || dis[nx][ny]) continue;
      dis[nx][ny] = dis[x][y] + 1;
      q.push({nx, ny});
    }
  }
}
