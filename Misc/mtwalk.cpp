#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int n, a[N][N];
bool vst[N][N];

bool dfs(int x, int y, int lo, int hi) {
  if (x < 1 || x > n || y < 1 || y > n) return false;
  if (vst[x][y] || a[x][y] < lo || a[x][y] > hi) return false;
  if (x == n && y == n) return true;
  vst[x][y] = true;
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i], ny = y + dy[i];
    if (dfs(nx, ny, lo, hi)) return true;
  }
  return false;
}

bool check(int x) {
  for (int i = 0; i + x <= 110; i++) {
    memset(vst, 0, sizeof(vst));
    if (dfs(1, 1, i, i + x)) return true;
  }
  return false;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++)
  for (int j = 1; j <= n; j++) {
    cin >> a[i][j];
  }
  int l = 0, r = 110, ans = -1;
  while (l <= r) {
    int x = (l + r) / 2;
    if (check(x)) {
      ans = x;
      r = x - 1;
    }
    else l = x + 1;
  }
  cout << ans << '\n';
}
