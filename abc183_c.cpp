#include <bits/stdc++.h>
using namespace std;

const int N = 10;

int n, k, sum = 0, ans = 0;
int dis[N][N], sav[N], vst[N];

void brute(int i) {
  for (int j = 2; j <= n; j++) {
    if (vst[j]) continue;
    sav[i] = j;
    vst[j] = 1;
    sum += dis[sav[i - 1]][j];
    if (i == n) {
      if (sum + dis[j][1] == k) ans++;
    }
    else brute(i + 1);
    vst[j] = 0;
    sum -= dis[sav[i - 1]][j];
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++)
  for (int j = 1; j <= n; j++) {
    cin >> dis[i][j];
  }
  sav[1] = 1;
  brute(2);
  cout << ans << '\n';
}
