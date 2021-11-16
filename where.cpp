#include <bits/stdc++.h>
using namespace std;

const int N = 25;

char a[N][N];
int vst[N][N];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  freopen("where.in" , "r", stdin );
  freopen("where.out", "w", stdout);
  int n; cin >> n;
  for (int i = 1; i <= n; i++)
  for (int j = 1; j <= n; j++) {
    cin >> a[i][j];
  }
  vector<array<int,4>> res;
  for (int x1 = 1; x1 <= n; x1++)
  for (int y1 = 1; y1 <= n; y1++)
  for (int x2 = 1; x2 <= n; x2++)
  for (int y2 = 1; y2 <= n; y2++) {
    memset(vst, 0, sizeof(vst));
    map<char,int> cnt;
    for (int i = x1; i <= x2; i++)
    for (int j = y1; j <= y2; j++) {
      if (!vst[i][j]) {
        cnt[a[i][j]]++;
        queue<pair<int,int>> q;
        q.push(make_pair(i, j));
        while (q.size()) {
          int x, y;
          tie(x, y) = q.front(); q.pop();
          if (vst[x][y]) continue;
          vst[x][y] = 1;
          for (int k = 0; k < 4; k++) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx < x1 || nx > x2 || ny < y1 || ny > y2) continue;
            if (a[x][y] != a[nx][ny] || vst[nx][ny]) continue;
            q.push(make_pair(nx, ny));
          }
        }
      }
    }
    if (cnt.size() == 2) {
      int t1 = cnt.begin()->second;
      int t2 = next(cnt.begin())->second;
      if ((t1 == 1 && t2 > 1) || (t1 > 1 && t2 == 1)) {
        res.push_back({x1, y1, x2, y2});
      }
    }
  }
  vector<int> rem(res.size());
  for (int i = 0; i < (int) res.size(); i++)
  for (int j = 0; j < (int) res.size(); j++) {
    if (i == j) continue;
    auto ri = res[i];
    auto rj = res[j];
    if (ri[0] >= rj[0] && ri[1] >= rj[1] && ri[2] <= rj[2] && ri[3] <= rj[3]) {
      rem[i] = 1;
    }
  }
  int ans = 0;
  for (int i = 0; i < (int) res.size(); i++) {
    if (!rem[i]) ans++;
  }
  cout << ans << '\n';
}
