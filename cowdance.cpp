#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  freopen("cowdance.in" , "r", stdin );
  freopen("cowdance.out", "w", stdout);
  int n, t_max;
  cin >> n >> t_max;
  vector<int> a(n);
  for (auto &i : a) cin >> i;
  auto check = [&](int k)->bool {
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < min(k, n); i++) {
      q.push(a[i]);
    }
    int t = 0, p = min(k, n);
    while (q.size()) {
      t = max(t, q.top()); q.pop();
      if (p < n) q.push(t + a[p++]);
    }
    return t <= t_max;
  };
  int l = 1, r = n, ans = -1;
  while (l <= r) {
    int x = (l + r) / 2;
    if (check(x)) {
      ans = x;
      r = x - 1;
    }
    else l = x + 1;
  }
  cout << ans << '\n';
}
