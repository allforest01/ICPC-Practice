#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

void Main() {
  int a, b, c;
  cin >> a >> b >> c;
  for (int i = 1; i <= a; i++) {
    if (i <= a - c + 1) {
      if (i == 1) cout << 1;
      else cout << 0;
    }
    else cout << 0;
  }
  cout << ' ';
  for (int i = 1; i <= b; i++) {
    if (i <= b - c + 1) {
      if (i == 1) cout << 2;
      else cout << 3;
    }
    else cout << 0;
  }
  cout << endl;
}

signed main() {
  // freopen("in" , "r", stdin );
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
