#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("censor.in" , "r", stdin );
  freopen("censor.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  string s, t;
  cin >> s >> t;
  for (int i = 0; i < (int)(s.size()) - (int)(t.size()) + 1; ) {
    bool flag = 0;
    for (int j = 0; j < t.size(); j++) {
      if (s[i + j] != t[j]) {
        flag = 1;
        break;
      }
    }
    if (!flag) {
      s.erase(i, t.size());
      i = max(0, i - (int)(t.size()) + 1);
    }
    else i++;
  }
  cout << s << '\n';
}
