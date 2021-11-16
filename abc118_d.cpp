#include <bits/stdc++.h>
using namespace std;

const int N = 10005;

int cost[10] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int sav[N][10], cnt[N];

bool cmp(int i, int j, int c) {
  for (int k = 9; k >= 0; k--) {
    if (sav[i][k] < sav[j][k] + (k == c)) return 1;
    if (sav[i][k] > sav[j][k] + (k == c)) return 0;
  }
  return 0;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(m);
  for (auto &i : a) cin >> i;
  for (int i = 1; i <= n; i++) {
    cnt[i] = INT_MIN;
    for (auto &j : a) {
      if (i < cost[j] || cnt[i - cost[j]] < 0) continue;
      if (cnt[i]  < cnt[i - cost[j]] + 1
      || (cnt[i] == cnt[i - cost[j]] + 1 && cmp(i, i - cost[j], j))) {
        cnt[i] = cnt[i - cost[j]] + 1;
        for (auto &k : a) {
          sav[i][k] = sav[i - cost[j]][k];
        }
        sav[i][j]++;
      }
    }
  }
  for (int i = 9; i >= 1; i--) {
    for (int j = 0; j < sav[n][i]; j++) {
      cout << i;
    }
  }
  cout << '\n';
}
