#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define pow abcdef_pow
#define vi vector<int>
#define vc vector<char>

const int MOD = 998244353;

int pow(int a, int b) {
  if (b == 0) return 1;
  int t = pow(a, b / 2);
  t = (t * t) % MOD;
  if (b % 2) return (t * a) % MOD;
  return t;
}

int add(int &a, int b) {
  a %= MOD;
  b %= MOD;
  a = (a + b) % MOD;
}

int sub(int &a, int b) {
  a %= MOD;
  b %= MOD;
  a = (a - b + MOD * MOD) % MOD;
}

signed main() {
  // freopen("in" , "r", stdin );
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<vc> s(n + 1, vc(m + 1));
  vector<vi> r(n + 1, vi(m + 1)), c(n + 1, vi(m + 1));
  int cnt = 0;
  for (int i = 1; i <= n; i++)
  for (int j = 1; j <= m; j++) {
    cin >> s[i][j];
    if (s[i][j] == 'o') {
      cnt++;
      r[i][j] = r[i][j - 1] + 1;
      c[i][j] = c[i - 1][j] + 1;
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++)
  for (int j = 1; j <= m; j++) {
    if (s[i][j] == 'o') {
      if (i == n || s[i + 1][j] == '*') {
        int t = c[i][j];
        for (int k = 2; k <= t; k++) {
          if (k % 2 == 0) add(ans, pow(2, cnt - k) * (t - k + 1));
          else sub(ans, pow(2, cnt - k) * (t - k + 1));
        }
      }
      if (j == m || s[i][j + 1] == '*') {
        int t = r[i][j];
        for (int k = 2; k <= t; k++) {
          if (k % 2 == 0) add(ans, pow(2, cnt - k) * (t - k + 1));
          else sub(ans, pow(2, cnt - k) * (t - k + 1));
        }
      }
    }
  }
  cout << ans << endl;
}
