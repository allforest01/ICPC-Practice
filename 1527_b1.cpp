#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

void Main() {
  int n; cin >> n;
  string s; cin >> s;
  int c = 0;
  for (auto &i : s) if (i == '0') c++;
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
  }
  else {
    cout << "ALICE" << endl;
  }
}

signed main() {
  // freopen("in" , "r", stdin );
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
