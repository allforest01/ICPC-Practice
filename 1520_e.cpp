#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

void Main() {
  int n; cin >> n;
  string s; cin >> s;
  vector<int> v;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '*') v.push_back(i);
  }
  int t = v.size() / 2, ans = 0;
  for (int i = 0; i < v.size(); i++) {
    ans += abs(v[i] - (v[t] + (i - t)));
  }
  cout << ans << endl;
}

signed main() {
  // freopen("in" , "r", stdin );
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
