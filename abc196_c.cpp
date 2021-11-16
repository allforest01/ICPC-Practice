#include <bits/stdc++.h>
using namespace std;

string s = "------";
long long n, ans = 0;

void check(int i) {
  if (s[0] == '0') return;
  string t = s.substr(0, i + 1);
  // reverse(t.begin(), t.end());
  t += s.substr(0, i + 1);
  long long x = stoll(t);
  if (x <= n) {
    ans++;
    // cout << x << '\n';
  }
}

void brute(int i) {
  for (s[i] = '0'; s[i] <= '9'; s[i]++) {
    check(i);
    if (i < 5) brute(i + 1);
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  brute(0);
  cout << ans << '\n';
}
