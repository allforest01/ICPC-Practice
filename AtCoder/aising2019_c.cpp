#include <bits/stdc++.h>
using namespace std;

const int N = 405;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int n, m; char a[N][N];
int vst[N][N];
long long black = 0, white = 0;

void dfs(int x, int y) {
  vst[x][y] = 1;
  if (a[x][y] == '#') black++; else white++;
  for (int i = 0; i < 4; i++) {
    int tx = x + dx[i];
    int ty = y + dy[i];
    if (tx < 0 || tx >= n || ty < 0 || ty >= m) continue;
    if (vst[tx][ty] || a[tx][ty] == a[x][y]) continue;
    dfs(tx, ty);
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++)
  for (int j = 0; j < m; j++) {
    cin >> a[i][j];
  }
  long long ans = 0;
  for (int i = 0; i < n; i++)
  for (int j = 0; j < m; j++) {
    if (!vst[i][j]) {
      dfs(i, j);
      ans += black * white;
      black = 0;
      white = 0;
    }
  }
  cout << ans << '\n';
}
