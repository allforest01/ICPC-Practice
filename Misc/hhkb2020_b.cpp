#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<string> s(n);
  for (auto &i : s) cin >> i;
  int ans = 0;
  for (int i = 0; i < n; i++)
  for (int j = 0; j < m; j++) {
    if (s[i][j] == '.') {
      if (i > 0 && s[i - 1][j] == '.') ans++;
      if (j > 0 && s[i][j - 1] == '.') ans++;
    }
  }
  cout << ans << '\n';
}
