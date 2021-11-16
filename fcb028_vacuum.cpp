#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int n, k, res[N][N];
bool a[N][N], vst[N][N];

int main() {
  cin >> n >> k;
  memset(vst, 1, sizeof(vst));
  for (int i = 1; i <= n; i++)
  for (int j = 1; j <= n; j++) {
    cin >> a[i][j];
    vst[i][j] = 0;
  }
  int x = 1, y = 1, dir = 0, cnt = -1;
  for (int i = 1; i <= n * n; i++) {
    vst[x][y] = 1;
    if (!a[x][y]) res[x][y] = ++cnt;
    int nx = x + dx[dir], ny = y + dy[dir];
    if (vst[nx][ny]) {
      dir = (dir + 1) % 4;
      nx = x + dx[dir];
      ny = y + dy[dir];
    }
    x = nx; y = ny;
  }
  k %= cnt * 2;
  if (k > cnt) k = cnt * 2 - k;
  for (int i = 1; i <= n; i++)
  for (int j = 1; j <= n; j++) {
    if (k == res[i][j]) {
      cout << i << ' ' << j << '\n';
      return 0;
    }
  }
}
