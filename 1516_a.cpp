#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

void Main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto &i : a) cin >> i;
  for (int i = 0; i < n - 1; i++) {
    int t = min(a[i], k);
    a[i] -= t;
    a[n - 1] += t;
    k -= t;
  }
  for (auto &i : a) cout << i << ' ';
  cout << endl;
}

signed main() {
  // freopen("in" , "r", stdin );
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
