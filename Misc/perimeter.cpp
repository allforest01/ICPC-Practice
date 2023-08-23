#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

char a[N][N];
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
int area, peri;

void dfs(int x, int y) {
  area++;
  a[x][y] = '$';
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (a[nx][ny] == '.') peri++;
    else if (a[nx][ny] == '#') dfs(nx, ny);
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  freopen("perimeter.in" , "r", stdin );
  freopen("perimeter.out", "w", stdout);
  int n; cin >> n;
  memset(a, '.', sizeof(a));
  for (int i = 1; i <= n; i++)
  for (int j = 1; j <= n; j++) {
    cin >> a[i][j];
  }
  int ans_area = 0, ans_peri = 0;
  for (int i = 1; i <= n; i++)
  for (int j = 1; j <= n; j++) {
    if (a[i][j] == '#') {
      area = 0; peri = 0;
      dfs(i, j);
      if (area > ans_area) {
        ans_area = area;
        ans_peri = peri;
      }
      else if (area == ans_area && peri < ans_peri) {
        ans_peri = peri;
      }
    }
  }
  cout << ans_area << ' ' << ans_peri << '\n';
}
