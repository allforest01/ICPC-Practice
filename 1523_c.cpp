#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

void Main() {
  int n; cin >> n;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    if (x == 1) v.push_back(1);
    else {
      while (x != v.back() + 1) v.pop_back();
      v.back()++;
    }
    for (int j = 0; j + 1 < v.size(); j++) {
      cout << v[j] << '.';
    }
    cout << v.back() << endl;
  }
}

signed main() {
  // freopen("in" , "r", stdin );
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
