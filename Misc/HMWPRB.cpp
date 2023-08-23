#include <bits/stdc++.h>
using namespace std;

#define int long long

void Main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  if (k >= n) {
    cout << 0 << '\n';
    return;
  }
  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
  pq.push(make_pair(0, 0));
  int ans = INT_MAX;
  for (int i = 1; i <= n; i++) {
    while (i - pq.top().second - 1 > k) pq.pop();
    int cal = a[i] + pq.top().first;
    pq.push(make_pair(cal, i));
    if (i >= n - k) ans = min(ans, cal);
  }
  cout << ans << '\n';
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  // freopen("in", "r", stdin);
  int T; cin >> T;
  while (T--) Main();
}
