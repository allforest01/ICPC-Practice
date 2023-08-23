#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

void Main() {
  int n; cin >> n;
  int d = n / 111;
  for (int i = max(0ll, d - 10); i <= d; i++) {
    if ((n - i * 111) % 11 == 0) {
      cout << "YES" << endl;
      return;
    }
  }
  cout << "NO" << endl;
}

signed main() {
  // freopen("in" , "r", stdin );
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
