#include <bits/stdc++.h>
using namespace std;

const int N = 200;

int a[N + 1], dp[N + 1][N][N][2][2][2];

void chmax(int &a, int b) {
  if (a < b) a = b;
}

int mod(int x) {
  return (x % N + N) % N;
}

int main() {
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] %= N;
  }
  dp[0][0][0][0][0][0] = 1;
  for (int i = 1; i <= n; i++)
  for (int j = 0; j < N; j++)
  for (int k = 0; k < N; k++)
  for (int l = 0; l < 2; l++) 
  for (int t = 0; t < 2; t++)
  for (int d = 0; d < 2; d++) {
    dp[i][j][k][l][t][d] = dp[i - 1][j][k][l][t][d];
    chmax(dp[i][j][k][t][l][d], dp[i - 1][mod(j - a[i])][k][0][l][0]);
    chmax(dp[i][j][k][l][t][d], dp[i - 1][j][mod(k - a[i])][l][0][0]);
    chmax(dp[i][j][k][l][t][d], dp[i - 1][mod(j - a[i])][mod(k - a[i])][0][0][d]);
  }
  int res = -1;
  for (int i = 0; i < N; i++) {
    if (dp[n][i][i][1][1][1]) res = i;
  }
  if (res == -1) {
    cout << "No" << '\n';
    return 0;
  }
  deque<int> b, c;
  {
    int i = n, j = res, k = res, l = 1, t = 1, d = 1;
    while (i > 0) {
      if (dp[i - 1][j][k][l][t][d]) {
        i--;
      }
      else if (dp[i - 1][mod(j - a[i])][k][0][t][0]) {
        b.push_front(i);
        j = mod(j - a[i]);
        l = 0;
        d = 0;
        i--;
      }
      else if (dp[i - 1][j][mod(k - a[i])][l][0][0]) {
        c.push_front(i);
        k = mod(k - a[i]);
        t = 0;
        d = 0;
        i--;
      }
      else if (dp[i - 1][mod(j - a[i])][mod(k - a[i])][0][0][d]) {
        b.push_front(i);
        c.push_front(i);
        j = mod(j - a[i]);
        k = mod(k - a[i]);
        l = 0;
        t = 0;
        i--;
      }
    }
  }
  cout << "Yes" << '\n';
  cout << b.size() << ' ';
  for (auto &i : b) cout << i << ' ';
  cout << '\n';
  cout << c.size() << ' ';
  for (auto &i : c) cout << i << ' ';
  cout << '\n';
}
