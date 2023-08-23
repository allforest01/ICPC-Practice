#include <bits/stdc++.h>
using namespace std;

const int N = 505;

int a[N][N], b[N][N], vst[N][N];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  freopen("ccski.in" , "r", stdin );
  freopen("ccski.out", "w", stdout);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
  for (int j = 1; j <= m; j++) {
    cin >> a[i][j];
  }
  int si = -1, sj = - 1;
  for (int i = 1; i <= n; i++)
  for (int j = 1; j <= m; j++) {
    cin >> b[i][j];
    if (b[i][j]) {
      si = i;
      sj = j;
    }
  }
  auto check = [&](int p) {
    memset(vst, 0, sizeof(vst));
    queue<pair<int,int>> q;
    q.push(make_pair(si, sj));
    while (q.size()) {
      int x, y;
      tie(x, y) = q.front(); q.pop();
      if (vst[x][y]) continue;
      vst[x][y] = 1;
      for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
        if (abs(a[x][y] - a[nx][ny]) > p) continue;
        q.push(make_pair(nx, ny));
      }
    }
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      if (b[i][j] && !vst[i][j]) {
        return false;
      }
    }
    return true;
  };
  int l = 0, r = 1e9, ans = -1;
  while (l <= r) {
    int p = (l + r) / 2;
    if (check(p)) {
      ans = p;
      r = p - 1;
    }
    else l = p + 1;
  }
  cout << ans << '\n';
}
