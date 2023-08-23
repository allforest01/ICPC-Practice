#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

void Main() {
  int n; cin >> n;
  vector<int> even, odd;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    if (x % 2 == 0) even.push_back(x);
    else odd.push_back(x);
  }
  for (auto &i : even) cout << i << ' ';
  for (auto &i : odd) cout << i << ' ';
  cout << endl;
}

signed main() {
  // freopen("in" , "r", stdin );
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
