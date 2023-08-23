#include <bits/stdc++.h>
using namespace std;

char a[10][10];
int n, k, ans = 0;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

void dfs(int i, int j, int k) {
  if (k == 0) {
    ans++;
    return;
  }
  vector<pair<int,int>> v;
  for (int i = 1; i <= n; i++)
  for (int j = 1; j <= n; j++) {
    if (a[i][j] == '.') {
      for (int d = 0; d < 4; d++) {
        int ni = i + dx[d], nj = j + dy[d];
        if (a[ni][nj] == '@') {
          a[i][j] = '@';
          dfs(i, j, k - 1);
          a[i][j] = '#';
          v.push_back(make_pair(i, j));
          break;
        }
      }
    }
  }
  for (auto &i : v) {
    a[i.first][i.second] = '.';
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> k;
  memset(a, '#', sizeof(a));
  for (int i = 1; i <= n; i++)
  for (int j = 1; j <= n; j++) {
    cin >> a[i][j];
  }
  for (int i = 1; i <= n; i++)
  for (int j = 1; j <= n; j++) {
    if (a[i][j] == '.') {
      a[i][j] = '@';
      dfs(i, j, k - 1);
      a[i][j] = '#';
    }
  }
  cout << ans << '\n';
}
