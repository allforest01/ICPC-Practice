#include <bits/stdc++.h>
using namespace std;

#define ar array

const int N = 505;

char a[N][N];
int vst[N][N];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
int px[] = {-2, -2, -2, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2, 2};
int py[] = {-1, 0, 1, -2, -1, 0, 1, 2, -2, -1, 0, 1, 2, -2, -1, 0, 1, 2, -1, 0, 1};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
  for (int j = 1; j <= m; j++) {
    cin >> a[i][j];
  }
  priority_queue<ar<int,3>, vector<ar<int,3>>, greater<ar<int,3>>> pq;
  pq.push({1, 1, 1});
  while (pq.size()) {
    auto t = pq.top(); pq.pop();
    int c = t[0], x = t[1], y = t[2];
    if (vst[x][y]) continue;
    vst[x][y] = c;
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i], ny = y + dy[i];
      if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
      if (a[nx][ny] == '#') continue;
      pq.push({c, nx, ny});
    }
    for (int i = 0; i < 21; i++) {
      int nx = x + px[i], ny = y + py[i];
      if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
      pq.push({c + 1, nx, ny});
    }
  }
  cout << vst[n][m] - 1 << '\n';
}
