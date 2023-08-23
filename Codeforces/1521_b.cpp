#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

void Main() {
  int n; cin >> n;
  vector<int> a(n);
  for (auto &i : a) cin >> i;
  cout << n / 2 << endl;
  for (int i = 1; i < n; i += 2) {
    cout << i << ' ' << i + 1 << ' ' << min(a[i - 1], a[i]) << ' ' << (int)(1e9) + 7 << endl;
  }
}

signed main() {
  // freopen("in" , "r", stdin );
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
