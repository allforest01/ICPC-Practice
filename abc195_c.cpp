#include <bits/stdc++.h>
using namespace std;

long long pow10(int x) {
  long long ret = 1;
  for (int i = 1; i <= x; i++) {
    ret *= 10;
  }
  return ret;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  string s;
  cin >> s;
  long long ans = 0;
  for (int i = 0; i + 1 < s.size(); i++) {
    ans += (i / 3) * pow10(i) * 9;
  }
  int n = s.size() - 1;
  ans += (n / 3) * pow10(n) * (s[0] - '1');
  for (int i = 1; i < s.size(); i++) {
    int t = s.size() - i;
    ans += (n / 3) * pow10(t - 1) * (s[i] - '0');
  }
  cout << ans + (n / 3) << '\n';
}
