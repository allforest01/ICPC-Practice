#include <bits/stdc++.h>
using namespace std;

void Main() {
  string s, t;
  cin >> s >> t;
  reverse(s.begin(), s.end());
  reverse(t.begin(), t.end());
  int n = s.size(), nt = t.size();
  s = '$' + s;
  t = '$' + t;
  for (int i = 1, j = 1; i <= nt; ) {
    while (j + 1 <= n && (s[j] != t[i] || !(((j - 1) - (i - 1)) % 2 == 0))) j++;
    if (j <= n && s[j] == t[i] && (((j - 1) - (i - 1)) % 2 == 0)) {
      i++;
      j++;
    }
    else {
      cout << "NO" << '\n';
      return;
    }
  }
  cout << "YES" << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
