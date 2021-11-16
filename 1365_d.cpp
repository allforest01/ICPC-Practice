#include <bits/stdc++.h>
using namespace std;

const int N = 55;

char a[N][N];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
int vst[N][N];

void dfs(int x, int y) {
  vst[x][y] = 1;
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (a[nx][ny] != '#' && !vst[nx][ny]) dfs(nx, ny);
  }
}

void Main() {
  int n, m;
  cin >> n >> m;
  memset(a, '#', sizeof(a));
  memset(vst, 0, sizeof(vst));
  for (int i = 1; i <= n; i++)
  for (int j = 1; j <= m; j++) {
    cin >> a[i][j];
  }
  for (int i = 1; i <= n; i++)
  for (int j = 1; j <= m; j++) {
    if (a[i][j] == 'B') {
      for (int k = 0; k < 4; k++) {
        int ni = i + dx[k];
        int nj = j + dy[k];
        if (a[ni][nj] == 'G') {
          cout << "No" << '\n';
          return;
        }
        if (a[ni][nj] == '.') {
          a[ni][nj] = '#';
        }
      }
    }
  }
  if (a[n][m] != '#') dfs(n, m);
  for (int i = 1; i <= n; i++)
  for (int j = 1; j <= m; j++) {
    if ((a[i][j] == 'G' && vst[i][j] == 0) or
        (a[i][j] == 'B' && vst[i][j] == 1)) {
      cout << "No" << '\n';
      return;
    }
  }
  cout << "Yes" << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
