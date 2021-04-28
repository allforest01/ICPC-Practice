#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int N = 2005;

int a[N], sum[N][N];

int solve(int l, int r) {
  if (l == r) {
    return sum[l][r] = 0;
  }
  if (sum[l][r] != -1) {
    return sum[l][r];
  }
  int dl = a[r] - a[l] + solve(l + 1, r);
  int dr = a[r] - a[l] + solve(l, r - 1);
  if (dl < dr) {
    return sum[l][r] = dl;
  }
  else {
    return sum[l][r] = dr;
  }
}

signed main() {
  // freopen("in" , "r", stdin );
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  memset(sum, -1, sizeof(sum));
  cout << solve(1, n) << endl;
}
