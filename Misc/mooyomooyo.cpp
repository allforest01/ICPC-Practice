#include <bits/stdc++.h>
using namespace std;

const int N = 105;

char a[N][15];
int n, k, vst[N][15];
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};

bool rem(int x, int y) {
  memset(vst, 0, sizeof(vst));
  int cnt = 0;
  queue<pair<int, int>> q;
  q.push(make_pair(x, y));
  while (q.size()) {
    int x, y;
    tie(x, y) = q.front(); q.pop();
    if (vst[x][y]) continue;
    vst[x][y] = 1;
    cnt++;
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i], ny = y + dy[i];
      if (nx < 1 || nx > n || ny < 1 || ny > 10) continue;
      if (a[x][y] != a[nx][ny] || vst[nx][ny]) continue;
      q.push(make_pair(nx, ny));
    }
  }
  if (cnt >= k) {
    for (int i = 1; i <=  n; i++)
    for (int j = 1; j <= 10; j++) {
      if (vst[i][j]) a[i][j] = '0';
    }
    return true;
  }
  return false;
}

void fall(int j) {
  vector<char> vec;
  for (int i = 1; i <= n; i++) {
    if (a[i][j] != '0') vec.push_back(a[i][j]);
  }
  int t = vec.size();
  for (int i = 1; i <= n - t; i++) {
    a[i][j] = '0';
  }
  for (int i = 1; i <= t; i++) {
    a[n - t + i][j] = vec[i - 1];
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  freopen("mooyomooyo.in" , "r", stdin );
  freopen("mooyomooyo.out", "w", stdout);
  cin >> n >> k;
  for (int i = 1; i <=  n; i++)
  for (int j = 1; j <= 10; j++) {
    cin >> a[i][j];
  }
  bool flag = true;
  while (flag) {
    flag = false;
    for (int i = 1; i <=  n; i++)
    for (int j = 1; j <= 10; j++) {
      if (a[i][j] != '0') {
        if (rem(i, j)) flag = true;
      }
    }
    for (int j = 1; j <= 10; j++) fall(j);
  }
  for (int i = 1; i <=  n; i++) {
    for (int j = 1; j <= 10; j++) {
      cout << a[i][j];
    }
    cout << '\n';
  }
}
