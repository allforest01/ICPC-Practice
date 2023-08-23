#include <bits/stdc++.h>
using namespace std;

const int N = 105;

vector<pair<int,int>> a[N][N];
int vst[N][N], lit[N][N];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  freopen("lightson.in" , "r", stdin );
  freopen("lightson.out", "w", stdout);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int x, y, u, v;
    cin >> x >> y >> u >> v;
    a[x][y].push_back(make_pair(u, v));
  }
  lit[1][1] = 1;
  queue<pair<int,int>> q;
  q.push(make_pair(1, 1));
  while (q.size()) {
    int x, y;
    tie(x, y) = q.front(); q.pop();
    if (vst[x][y]) continue;
    vst[x][y] = 1;
    for (auto &i : a[x][y]) {
      int nx, ny;
      tie(nx, ny) = i;
      lit[nx][ny] = 1;
      for (int j = 0; j < 4; j++) {
        int nnx = nx + dx[j], nny = ny + dy[j];
        if (vst[nnx][nny]) {
          q.push(make_pair(nx, ny));
          break;
        }
      }
    }
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i], ny = y + dy[i];
      if (nx < 1 || nx > n || ny < 1 || ny > n) continue;
      if (!lit[nx][ny]) continue;
      q.push(make_pair(nx, ny));
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++)
  for (int j = 1; j <= n; j++) {
    if (lit[i][j]) ans++;
  }
  cout << ans << '\n';
}
