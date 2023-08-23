#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int n, m; char a[N][N];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

void bfs(int x, int y) {
  queue<pair<int,int>> q;
  q.push({x, y});
  while (q.size()) {
    int x, y;
    tie(x, y) = q.front(); q.pop();
    a[x][y] = '.';
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i], ny = y + dy[i];
      if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
      if (a[nx][ny] == '.') continue;
      q.push({nx, ny});
    }
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
  for (int j = 1; j <= m; j++) {
    cin >> a[i][j];
  }
  int ans = 0;
  for (int i = 1; i <= n; i++)
  for (int j = 1; j <= m; j++) {
    if (a[i][j] == '#') {
      ans++;
      bfs(i, j);
    }
  }
  cout << ans << '\n';
}
