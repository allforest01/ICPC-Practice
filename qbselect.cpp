#include <bits/stdc++.h>
using namespace std;

const int N = 10005;

int a[10][N], dp[25][N];

int getBit(int x, int k) {
  return x & (1 << k);
}

bool isSat(int a, int b) {
  for (int i = 0; i < 4; i++) {
    if (getBit(a, i) & getBit(b, i)) {
      return false;
    }
  }
  return true;
}

void chmax(int &a, int b) {
  if (a < b) a = b;
}

int main() {
  int n; cin >> n;
  int amax = -2e9;
  bool allneg = true;
  for (int i = 1; i <= 4; i++)
  for (int j = 1; j <= n; j++) {
    cin >> a[i][j];
    chmax(amax, a[i][j]);
    if (a[i][j] >= 0) allneg = false;
  }
  if (allneg) {
    cout << amax << '\n';
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < (1 << 4); j++) {
      if (!isSat(j, j << 1)) continue;
      int curSum = 0;
      for (int k = 0; k < 4; k++) {
        if (getBit(j, k)) curSum += a[k + 1][i];
      }
      dp[j][i] = -2e9;
      for (int k = 0; k < (1 << 4); k++) {
        if (!isSat(j, k)) continue;
        chmax(dp[j][i], dp[k][i - 1] + curSum);
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < (1 << 4); i++) {
    chmax(ans, dp[i][n]);
  }
  cout << ans << '\n';
}