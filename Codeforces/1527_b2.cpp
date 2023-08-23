#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

void Main() {
  int n; cin >> n;
  string s; cin >> s;
  int d = 0, c = 0;
  for (int i = 0; i < n / 2; i++) {
    if (s[i] != s[n - i - 1]) d++;
  }
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') c++;
  }
  if (d == 0) {
    if (c == 0) {
      cout << "DRAW" << endl;
      return;
    }
    if (c == 1) {
      cout << "BOB" << endl;
      return;
    }
    if (c % 2 == 0) {
      cout << "BOB" << endl;
      return;
    }
    if (c % 2 == 1) {
      cout << "ALICE" << endl;
      return;
    }
  }
  if (c == 2 && d == 1 && n % 2 && s[n / 2] == '0') {
    cout << "DRAW" << endl;
    return;
  }
  cout << "ALICE" << endl;  
}

signed main() {
  // freopen("in" , "r", stdin );
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
