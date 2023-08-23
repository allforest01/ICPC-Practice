#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

void Main() {
  int n; cin >> n;
  if (n == 2) {
    cout << -1 << endl;
    return;
  }
  int c = 0;
  vector<vector<int>> a(n + 1, vector<int>(n + 1));
  for (int i = 1; i <= n; i++)
  for (int j = 1; j <= n; j++) {
    if ((i + j) % 2 == 0) a[i][j] = ++c;
  }
  for (int i = 1; i <= n; i++)
  for (int j = 1; j <= n; j++) {
    if ((i + j) % 2) a[i][j] = ++c;
  }
  for (int i = 1; i <= n; i++)
  for (int j = 1; j <= n; j++) {
    cout << a[i][j] << " \n"[j == n];
  }
}

signed main() {
  // freopen("in" , "r", stdin );
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
