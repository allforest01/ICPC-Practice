#include <bits/stdc++.h>
using namespace std;

const int N = 105;

double mem[N][N][N];

double dp(int a, int b, int c) {
  if (a == 100 || b == 100 || c == 100) return 0;
  if (mem[a][b][c] != -1) return mem[a][b][c];
  double ret = 1;
  ret += (double) a / (a + b + c) * dp(a + 1, b, c);
  ret += (double) b / (a + b + c) * dp(a, b + 1, c);
  ret += (double) c / (a + b + c) * dp(a, b, c + 1);
  return mem[a][b][c] = ret;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  for (int i = 0; i < N; i++)
  for (int j = 0; j < N; j++)
  for (int k = 0; k < N; k++) {
    mem[i][j][k] = -1;
  }
  int a, b, c;
  cin >> a >> b >> c;
  cout << setprecision(10) << fixed << dp(a, b, c) << '\n';
}
