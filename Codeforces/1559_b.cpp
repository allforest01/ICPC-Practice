#include <bits/stdc++.h>
using namespace std;

char rev(char c) {
  if (c == 'R') return 'B';
  if (c == 'B') return 'R';
  if (c == '?') return '?';
}

void Main() {
  int n; cin >> n;
  string s;
  cin >> s;
  bool flag = 1;
  for (auto &i : s) {
    if (i != '?') {
      flag = 0;
      break;
    }
  }
  if (flag) {
    for (int i = 0; i < n; i++) {
      if (i % 2) s[i] = 'R';
      else s[i] = 'B';
    }
    cout << s << '\n';
    return;
  }
  int t = n;
  while (t--) {
    for (int i = 0; i < n; i++) {
      if (s[i] == '?') {
        if (i > 0 && s[i - 1] != '?') {
          s[i] = rev(s[i - 1]);
        }
        else if (i + 1 < n && s[i + 1] != '?') {
          s[i] = rev(s[i + 1]);
        }
      }
    }
  }
  cout << s << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
