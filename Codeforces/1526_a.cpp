#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

void Main() {
  int n; cin >> n;
  vector<int> a(n * 2);
  for (auto &i : a) cin >> i;
  sort(a.begin(), a.end());
  for (int i = 0; i < n; i++) {
    cout << a[i] << ' ' << a[n * 2 - i - 1] << ' ';
  }
  cout << '\n';
}

signed main() {
  // freopen("in" , "r", stdin );
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
