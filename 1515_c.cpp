#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define ii pair<int,int>
#define fi first
#define sc second

void Main() {
  int n, m, x;
  cin >> n >> m >> x;
  vector<ii> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].fi;
    a[i].sc = i + 1;
  }
  sort(a.begin(), a.end());
  int s = 1;
  if (n % m) s = m - (n % m) + 1;
  vector<int> res(n + 1);
  for (int i = 0; i < n; i++) {
    res[a[i].sc] = s;
    s++;
    if (s == m + 1) s = 1;
  }
  cout << "YES" << endl;
  for (int i = 1; i <= n; i++) {
    cout << res[i] << ' ';
  }
  cout << endl;
}

signed main() {
  // freopen("in" , "r", stdin );
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
