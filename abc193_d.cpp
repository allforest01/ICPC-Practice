#include <bits/stdc++.h>
using namespace std;

#define int long long

int pow10(int n) {
  int ret = 1;
  for (int i = 1; i <= n; i++) {
    ret *= 10;
  }
  return ret;
}

int sum(int n) {
  return n * (n + 1) / 2;
}

int cal(vector<int> a, int x) {
  a[x]++;
  int ret = 0;
  for (int i = 1; i <= 9; i++) {
    ret += i * pow10(a[i]);
  }
  return ret;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; string s, t;
  cin >> n >> s >> t;
  vector<int> cs(10), ct(10);
  for (int i = 0; i < 4; i++) {
    cs[s[i] - '0']++;
    ct[t[i] - '0']++;
  }
  int ans = 0, cnt = sum(9 * n - 8 - 1) * 2;;
  for (int i = 1; i <= 9; i++)
  for (int j = 1; j <= 9; j++) {
    bool flag = 0;
    for (int k = 1; k <= 9; k++) {
      if (cs[k] + ct[k] + (i == k) + (j == k) > n) {
        // cout << i << ' ' << j << '\n';
        flag = 1;
        break;
      }
    }
    if (!flag && cal(cs, i) > cal(ct, j)) {
      if (i != j) {
        ans += (n - cs[i] - ct[i]) * (n - cs[j] - ct[j]);
      }
      else {
        ans += (n - cs[i] - ct[i]) * (n - cs[i] - ct[i] - 1);
      }
    }
  }
  cout << setprecision(10) << fixed;
  cout << (double) ans / cnt << '\n';
}
