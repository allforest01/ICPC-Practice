#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

void Main() {
  int n; cin >> n;
  vector<int> a(n);
  int sum = 0;
  for (auto &i : a) {
    cin >> i;
    sum += i;
  }
  if (sum % n) {
    cout << -1 << endl;
    return;
  }
  int ans = 0;
  for (auto &i : a) {
    if (i > sum / n) ans++;
  }
  cout << ans << endl;
}

signed main() {
  // freopen("in" , "r", stdin );
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
