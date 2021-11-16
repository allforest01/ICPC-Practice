#include <bits/stdc++.h>
using namespace std;

#define task "SYM"

const int N = 505;

int dp[N][N];

int main(){
  freopen(task".INP", "r", stdin );
  freopen(task".OUT", "w", stdout);
  string s;
  cin >> s;
  int n = s.size();
  s = '#' + s;
  for (int k = 1; k <= n; k++)
  for (int i = 1; i + k - 1 <= n; i++) {
    int j = i + k - 1;
    if (s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1];
    else dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
  }
  cout << dp[1][n] << '\n';
  int i = 1, j = n, l = 0;
  while (i < j) {
    if (s[i] == s[j]) {
      i++;
      j--;
    }
    else {
      if (dp[i + 1 - l][j - l] < dp[i - l][j - 1 - l]) {
        s.insert(j + 1, 1, s[i]);
        i++;
      }
      else {
        s.insert(i, 1, s[j]);
        i++;
        l++;
      }
    }
  }
  cout << s.substr(1, s.size() - 1) << '\n';
}
