#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

set<int> s;

void Init() {
  for (int i = 1; i * i <= 1e9; i++) {
    s.insert(i * i);
  }
}

void Main() {
  int n; cin >> n;
  if ((n % 2 == 0 && s.count(n / 2))
   || (n % 4 == 0 && s.count(n / 4))) {
    cout << "YES" << endl;
  }
  else {
    cout << "NO" << endl;
  }
}

signed main() {
  // freopen("in" , "r", stdin );
  cin.tie(0)->sync_with_stdio(0);
  Init();
  int T; cin >> T;
  while (T--) Main();
}
