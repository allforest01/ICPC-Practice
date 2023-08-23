#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  string s;
  cin >> s;
  bool flag = 0;
  int sc[2]{0, 0};
  for (int i = 0; i < s.size(); i += 2) {
    sc[s[i] - 'A'] += s[i + 1] - '0';
    if (sc[0] == 10 && sc[1] == 10) flag = 1;
    if (flag) {
      if (sc[0] - sc[1] >= 2) {
        cout << 'A' << '\n';
        return 0;
      }
      if (sc[1] - sc[0] >= 2) {
        cout << 'B' << '\n';
        return 0;
      }
    }
    else {
      if (sc[0] >= 11) {
        cout << 'A' << '\n';
        return 0;
      }
      if (sc[1] >= 11) {
        cout << 'B' << '\n';
        return 0;
      }
    }
  }
}
