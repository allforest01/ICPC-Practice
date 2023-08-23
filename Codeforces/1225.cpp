#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  long long ans = 0;
  map<vector<array<int,2>>,int> mem;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    vector<array<int,2>> div;
    for (int i = 2; i * i <= x; i++) {
      if (x % i) continue;
      int cnt = 0;
      while (x % i == 0) {
        cnt++;
        x /= i;
      }
      if (cnt % k) div.push_back({i, cnt % k});
    }
    if (x > 1) div.push_back({x, 1});
    vector<array<int,2>> rev;
    for (int i = 0; i < (int) div.size(); i++) {
      int t = ((k - div[i][1]) % k + k) % k;
      if (t) rev.push_back({div[i][0], t});
    }
    if (mem.count(rev)) ans += mem[rev];
    mem[div]++;
  }
  cout << ans << '\n';
}