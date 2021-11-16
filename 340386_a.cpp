#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  s = '#' + s;
  vector<array<array<int,3>,3>> sum(n + 1);
  for (int i = 1; i <= n; i++) {
    sum[i][i % 3][s[i] - 'a']++;
    for (int j = 0; j < 3; j++)
    for (int k = 0; k < 3; k++) {
      sum[i][j][k] += sum[i - 1][j][k];
    }
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    vector<int> per = {0, 1, 2};
    int ans = r - l + 1;
    do {
      int s = 0;
      for (int i = 0; i < 3; i++) {
        s += sum[r][i][per[i]] - sum[l - 1][i][per[i]];
      }
      ans = min(ans, (r - l + 1) - s);
    }
    while (next_permutation(per.begin(), per.end()));
    cout << ans << '\n';
  }
}
