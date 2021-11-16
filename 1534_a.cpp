#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

void Main() {
  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  int w = -1, r = -1;
  for (auto &i : a) cin >> i;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int t = (i + j) % 2;
      if (a[i][j] == 'W') {
        if (w == -1) w = t;
        else if (w != t) {
          cout << "NO" << endl;
          return;
        }
      }
      if (a[i][j] == 'R') {
        if (r == -1) r = t;
        else if (r != t) {
          cout << "NO" << endl;
          return;
        }
      }
    }
  }
  if (r == -1 && w == -1) {
    r = 0; w = 1;
  }
  if (r == w) {
    cout << "NO" << endl;
    return;
  }
  if (r != -1) w = 1 - r;
  if (w != -1) r = 1 - w;
  cout << "YES" << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (w == (i + j) % 2) {
        cout << 'W';
      }
      else cout << 'R';
    }
    cout << '\n';
  }
}

signed main() {
  // freopen("in" , "r", stdin );
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
