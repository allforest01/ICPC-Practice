#include <bits/stdc++.h>
using namespace std;

const int N = 205;
const int INF = 0x3f3f3f3f;

struct pos {
  int x, y, d, c;
  pos() {}
  pos(int x, int y, int d, int c): x(x), y(y), d(d), c(c) {}
  bool operator()(pos a, pos b) {
    return a.c > b.c;
  }
};

int dx[4] = {-1, -1, +1, +1};
int dy[4] = {-1, +1, -1, +1};

int n, m, p, q, s, t;
int vst[N][N][5], dis[N][N][5];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m >> p >> q >> s >> t;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    for (int j = 0; j < 4; j++) {
      vst[x][y][j] = 1;
    }
  }
  memset(dis, 0x3f, sizeof(dis));
  for (int i = 0; i < 4; i++) {
    vst[p][q][i] = 1;
    dis[p][q][i] = 0;
  }
  priority_queue<pos, vector<pos>, pos> que;
  for (int i = 0; i < 4; i++) {
    que.push(pos(p + dx[i], q + dy[i], i, 1));
  }
  while (que.size()) {
    auto i = que.top(); que.pop();
    int x = i.x, y = i.y, d = i.d, c = i.c;
    if (x < 1 || x > n || y < 1 || y > n) continue;
    if (vst[x][y][d]) continue;
    vst[x][y][d] = 1;
    dis[x][y][d] = c;
    for (int j = 0; j < 4; j++) {
      que.push(pos(x + dx[j], y + dy[j], j, c + (d != j)));
    }
  }
  int ans = INF;
  for (int i = 0; i < 4; i++) {
    ans = min(ans, dis[s][t][i]);
  }
  if (ans == INF) ans = -1;
  cout << ans << '\n';
}
