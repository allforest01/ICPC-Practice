#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int x, n;
  cin >> x >> n;
  priority_queue<ll, vector<ll>, greater<ll>> pq;
  for (int i = 0; i < n; i++) {
    int t; cin >> t;
    pq.push(t);
  }
  ll ans = 0;
  while (pq.size() > 1) {
    auto i = pq.top(); pq.pop();
    auto j = pq.top(); pq.pop();
    ans += i + j;
    pq.push(i + j);
  }
  cout << ans << '\n';
}
