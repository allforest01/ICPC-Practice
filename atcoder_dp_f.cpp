#include <bits/stdc++.h>
using namespace std;

int main() {
  string s, t;
  cin >> s >> t;
  int ns = s.size(), nt = t.size();
  s = '#' + s + '#';
  t = '#' + t + '#';
  vector<vector<int>> dp(ns + 1, vector<int>(nt + 1));
  for (int i = 1; i <= ns; i++)
  for (int j = 1; j <= nt; j++) {
    if (s[i] == t[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
    else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
  }
  string res;
  {
    int i = ns, j = nt;
    while (i && j) {
      if (s[i] == t[j]) res += s[i], i--, j--;
      else {
        if (dp[i - 1][j] > dp[i][j - 1]) i--; else j--;
      }
    }
  }
  reverse(res.begin(), res.end());
  cout << res << '\n';
}