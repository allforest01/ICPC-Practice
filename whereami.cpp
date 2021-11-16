#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  freopen("whereami.in" , "r", stdin );
  freopen("whereami.out", "w", stdout);
  int n; string s;
  cin >> n >> s;
  for (int len = 1; len <= n; len++) {
    set<string> d;
    int flag = 0;
    for (int i = 0; i + len - 1 < n; i++) {
      string t = s.substr(i, len);
      if (d.count(t)) {
        flag = 1;
        break;
      }
      d.insert(t);
    }
    if (!flag) {
      cout << len << '\n';
      return 0;
    }
  }
}
