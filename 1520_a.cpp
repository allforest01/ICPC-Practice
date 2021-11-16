#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

void Main() {
  int n; cin >> n;
  string s; cin >> s;
  map<char, int> m;
  for (int i = 0; i < s.size(); i++) {
    if (m.count(s[i]) && m[s[i]] != i - 1) {
      cout << "NO" << endl;
      return;
    }
    m[s[i]] = i;
  }
  cout << "YES" << endl;
}

signed main() {
  // freopen("in" , "r", stdin );
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
