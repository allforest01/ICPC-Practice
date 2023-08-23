#include <bits/stdc++.h>
using namespace std;
 
// ----------- define --------------
#define int long long
#define vi vector<int>
#define ii pair<int,int>
#define fi first
#define sc second
#define stoi stoll
#define popcnt __builtin_popcount
#define getbit(x, k) ((x >> k) & 1)
#define all(x) (x).begin(),(x).end()
// ---------------------------------
 
void Main() {
  int n, l, r;
  cin >> n >> l >> r;
  vector<int> a(n + 1);
  vector<vi> sp(n + 1, vi(20));
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] += a[i - 1];
    sp[i][0] = a[i];
  }
  for (int j = 1; (1 << (j - 1)) < n; j++) {
    for (int i = 1; i + (1 << (j - 1)) <= n; i++) {
      sp[i][j] = min(sp[i][j - 1], sp[i + (1 << (j - 1))][j - 1]);
    }
  }
  auto getMin = [&sp](int l, int r) {
    int d = r - l + 1;
    int i = 0;
    while (1 << (i + 1) < d) i++;
    return min(sp[l][i], sp[r - (1 << i) + 1][i]);
  };
  int ans = -1e18;
  for (int i = l; i <= n; i++) {
    int cal = a[i] - getMin(max(i - r, 0ll), max(i - l, 0ll));
    ans = max(ans, cal);
  }
  cout << ans << '\n';
}
 
signed main() {
  // freopen("in" , "r", stdin );
  // freopen("out", "w", stdout);
  // ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) Main();
}