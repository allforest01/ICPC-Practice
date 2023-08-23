#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

signed main() {
  // freopen("in" , "r", stdin );
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    if ((a <= 1 && b <= 2) || (a <= 2 && b <= 1)) {
      cout << "Yes" << endl;
    }
    else {
      cout << "No" << endl;
    }
  }
}
