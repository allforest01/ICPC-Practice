#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

signed main() {
  // freopen("in" , "r", stdin );
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<int> x(n), y(n);
  for (auto &i : x) cin >> i;
  for (auto &i : y) cin >> i;
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());
  for (int i = 0; i < n; i++) {
    if (x[i] > y[i]) {
      cout << "NE" << endl;
      return 0;
    }
  }
  cout << "DA" << endl;
}
