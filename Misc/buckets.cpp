#include <bits/stdc++.h>
using namespace std;

char a[10][10];
int dt[10][10];

int dx[]{0, -1, 0, 1};
int dy[]{-1, 0, 1, 0};

int main() {
  freopen("buckets.in" , "r", stdin );
  freopen("buckets.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  tuple<int,int,int> start;
  for (int i = 0; i < 10; i++)
  for (int j = 0; j < 10; j++) {
    cin >> a[i][j];
    if (a[i][j] == 'B') start = make_tuple(i, j, 1);
  }
  queue<tuple<int,int,int>> q;
  q.push(start);
  while (q.size()) {
    int x, y, c;
    tie(x, y, c) = q.front(); q.pop();
    if (x < 0 || x >= 10 || y < 0 || y >= 10) continue;
    if (dt[x][y] || a[x][y] == 'R') continue;
    dt[x][y] = c;
    if (a[x][y] == 'L') {
      cout << dt[x][y] - 2 << '\n';
      return 0;
    }
    for (int i = 0; i < 4; i++) {
      q.push(make_tuple(x + dx[i], y + dy[i], c + 1));
    }
  }
}
