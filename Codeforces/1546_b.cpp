#include <bits/stdc++.h>
using namespace std;

int Main() {
  int n, m;
  cin >> n >> m;
  vector<string> s(n);
  for (auto &i : s) {
    cin >> i;
  }
  vector<vector<int>> cnt(m, vector<int>(26));
  for (int j = 0; j < m; j++) {
    for (int i = 0; i < n; i++) {
      cnt[j][s[i][j] - 'a']++;
    }
  }
  vector<string> s2(n - 1);
  for (auto &i : s2) {
    cin >> i;
  }
  vector<vector<int>> cnt2(m, vector<int>(26));
  for (int j = 0; j < m; j++) {
    for (int i = 0; i < n - 1; i++) {
      cnt2[j][s2[i][j] - 'a']++;
    }
  }
  string res;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < 26; j++) {
      if (cnt2[i][j] < cnt[i][j]) res += (char)(j + 'a');
    }
  }
  cout << res << '\n';
  fflush(stdout);
}

int main() {
  // cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
