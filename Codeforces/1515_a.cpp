#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

void Main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  int s = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    s += a[i];
    if (s == k) {
      if (i == n - 1) {
        cout << "NO" << endl;
        return;
      }
      swap(a[i], a[i + 1]);
      break;
    }
  }
  cout << "YES" << endl;
  for (auto &i : a) cout << i << ' ';
  cout << endl;
}

signed main() {
  // freopen("in" , "r", stdin );
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
