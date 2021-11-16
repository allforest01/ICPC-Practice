#include <bits/stdc++.h>
using namespace std;

#define ar array

const int N = 105;
const int A = 30005;
const int MOD = 1e9;

int n, m;
int isPrime[A], pos[A];
int a[N][N], cnt[N][N];
vector<ar<int,2>> group[A];
vector<int> prime;

void primeSieve() {
  for (int i = 2; i < A; i++) {
    isPrime[i] = 1;
  }
  for (int i = 2; i < A; i++) {
    if (!isPrime[i]) continue;
    for (int j = i * 2; j < A; j += i) {
      isPrime[j] = 0;
    }
  }
  for (int i = 2; i < A; i++) {
    if (isPrime[i]) prime.push_back(i);
  }
}

int id(int i, int j) {
  return (i - 1) * m + (j - 1) % m + 1;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  primeSieve();
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
  for (int j = 1; j <= m; j++) {
    cin >> a[i][j];
    for (auto &k : prime) {
      if (a[i][j] < k) break;
      if (a[i][j] % k == 0) {
        group[k].push_back({i, j});
      }
    }
    if (j == 1) cnt[i][j] = 1;
  }
  for (int i = 1; i <= n * m; i++) {
    set<ar<int,2>> seen;
    for (auto &j : prime) {
      if (pos[j] == (int) group[j].size()) continue;
      int cur_x = group[j][pos[j]][0];
      int cur_y = group[j][pos[j]][1];
      if (id(cur_x, cur_y) != i) continue;
      for (int l = pos[j] + 1; l < (int) group[j].size(); l++) {
        int nxt_x = group[j][l][0];
        int nxt_y = group[j][l][1];
        if (cur_y < m && cur_x <= nxt_x && cur_y <= nxt_y
        && cur_x + cur_y < nxt_x + nxt_y && !seen.count({id(cur_x, cur_y), id(nxt_x, nxt_y)})) {
          (cnt[nxt_x][nxt_y] += cnt[cur_x][cur_y]) %= MOD;
          seen.insert({id(cur_x, cur_y), id(nxt_x, nxt_y)});
        }
      }
      pos[j]++;
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    (ans += cnt[i][m]) %= MOD;
  }
  cout << ans << '\n';
}