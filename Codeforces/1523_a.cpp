#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

void Main() {
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  vector<int> al(n, 2e9), ar(n, 2e9);
  int l = 0, d = 0;
  while (l < n && s[l] == '0') l++;
  while (l < n) {
    if (s[l] == '1') d = 0; else d++;
    al[l] = d;
    l++;
  }
  int r = n - 1; d = 0;
  while (r >= 0 && s[r] == '0') r--;
  while (r >= 0) {
    if (s[r] == '1') d = 0; else d++;
    ar[r] = d;
    r--;
  }
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') cout << 1;
    else {
      if ((al[i] <= m && ar[i] > m) || (al[i] > m && ar[i] <= m)) {
        cout << 1;
      }
      else {
        cout << 0;
      }
    }
  }
  cout << endl;
}

signed main() {
  // freopen("in" , "r", stdin );
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
