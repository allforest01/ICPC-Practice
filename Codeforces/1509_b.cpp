#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

void Main() {
  int n; cin >> n;
  string s; cin >> s;
  int t = 0, m = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'T') t++;
    if (s[i] == 'M') m++;
    if (m > t) {
      cout << "NO" << endl;
      return;
    }
  }
  t = 0, m = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == 'T') t++;
    if (s[i] == 'M') m++;
    if (m > t) {
      cout << "NO" << endl;
      return;
    }
  }
  if (t != m * 2) {
    cout << "NO" << endl;
    return;
  }
  cout << "YES" << endl;
}

signed main() {
  // freopen("in" , "r", stdin );
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
