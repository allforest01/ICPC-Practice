#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int k;
  cin >> k;
  string s;
  for (string t; cin >> t; ) s += t + ' ';
  s.erase(prev(s.end()));
  int n = s.size();
  for (auto &i : s) {
    if (i == ' ' || i == '-') i = '.';
  }
  auto check = [&](int x) {
    int i = 0, sum = 0, cnt = 1;
    while (i < n) {
      int j = i;
      while (j + 1 < n && s[j] != '.') j++;
      int len = j - i + 1;
      if (len > x) return false;
      sum += len;
      if (sum > x) {
        sum = len;
        cnt++;
      }
      i = j + 1;
    }
    return cnt <= k;
  };
  int l = 1, r = n, ans = -1;
  while (l <= r) {
    int x = (l + r) / 2;
    if (check(x)) {
      ans = x;
      r = x - 1;
    }
    else l = x + 1;
  }
  cout << ans << '\n';
}
