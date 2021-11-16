#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

signed main() {
  // freopen("in" , "r", stdin );
  cin.tie(0)->sync_with_stdio(0);
  string t = "heidi";
  string s; cin >> s;
  int j = 0;
  for (int i = 0; i < t.size(); i++) {
    while (j < s.size() && t[i] != s[j]) j++;
    if (j >= s.size() || t[i] != s[j]) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
}
