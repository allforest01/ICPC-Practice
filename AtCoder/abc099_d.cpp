#include <bits/stdc++.h>
using namespace std;

const int N = 500;
const int C = 30;

int n, d[3][C];
int c, b[C][C];
int color[3], mark[C];
int ans = INT_MAX;

void check() {
  int cal = 0;
  for (int i = 0; i < 3; i++) {
    cal += d[i][color[i]];
  }
  ans = min(ans, cal);
}

void brute(int i) {
  for (int j = 0; j < c; j++) {
    if (mark[j]) continue;
    mark[j] = true;
    color[i] = j;
    if (i == 2) check();
    else brute(i + 1);
    mark[j] = false;
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> c;
  for (int i = 0; i < c; i++)
  for (int j = 0; j < c; j++) {
    cin >> b[i][j];
  }
  for (int i = 0; i < n; i++)
  for (int j = 0; j < n; j++) {
    int x; cin >> x; x--;
    for (int k = 0; k < c; k++) {
      d[(i + j) % 3][k] += b[x][k];
    }
  }
  brute(0);
  cout << ans << '\n';
}
