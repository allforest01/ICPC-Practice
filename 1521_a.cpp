#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

void Main() {
  int a, b;
  cin >> a >> b;
  if (b == 1) {
    cout << "NO" << endl;
    return;
  }
  cout << "YES" << endl;
  cout << a << ' ' << a * (b * 2 - 1) << ' ' << a * b * 2 << endl;
}

signed main() {
  // freopen("in" , "r", stdin );
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
