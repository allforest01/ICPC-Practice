#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, q; string s;
  cin >> n >> q >> s;
  s = '#' + s;
  vector<array<int,3>> sum_pos(n + 1);
  vector<array<array<int,3>,3>> sum_cnt(n + 1);
  for (int i = 1; i <= n; i++) {
    sum_pos[i][i % 3]++;
    sum_cnt[i][i % 3][s[i] - 'a']++;
    for (int j = 0; j <= 2; j++) {
      sum_pos[i][j] += sum_pos[i - 1][j];
    }
    for (int j = 0; j <= 2; j++)
    for (int k = 0; k <= 2; k++) {
      sum_cnt[i][j][k] += sum_cnt[i - 1][j][k];
    }
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    array<int,3> pos;
    array<array<int,3>,3> cnt;
    for (int i = 0; i <= 2; i++) {
      pos[i] = sum_pos[r][i] - sum_pos[l - 1][i];
    }
    for (int i = 0; i <= 2; i++)
    for (int j = 0; j <= 2; j++) {
      cnt[i][j] = sum_cnt[r][i][j] - sum_cnt[l - 1][i][j];
    }
    vector<int> per = {0, 1, 2};
    int ans = INT_MAX;
    do {
      int cal = 0;
      for (int i = 0; i <= 2; i++) {
        cal += pos[i] - cnt[i][per[i]];
      }
      ans = min(ans, cal);
    } while (next_permutation(per.begin(), per.end()));
    cout << ans << '\n';
  }
}
