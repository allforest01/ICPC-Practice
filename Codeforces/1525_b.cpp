#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

void Main() {
  int n; cin >> n;
  vector<int> a(n);
  for (auto &i : a) cin >> i;
  if (is_sorted(a.begin(), a.end())) {
    cout << 0 << endl;
    return;
  }
  if (a[0] == 1 || a[n - 1] == n) {
    cout << 1 << endl;
    return;
  }
  if (a[0] == n && a[n - 1] == 1) {
    cout << 3  << endl;
    return;
  }
  cout << 2 << endl;
}

signed main() {
  // freopen("in" , "r", stdin );
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
