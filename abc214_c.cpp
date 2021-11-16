#include <bits/stdc++.h>
using namespace std;

#define ar array
#define int long long

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<int> s(n), t(n), res(n);
  for (auto &i : s) cin >> i;
  for (auto &i : t) cin >> i;
  priority_queue<ar<int,2>, vector<ar<int,2>>, greater<ar<int,2>>> pq;
  for (int i = 0; i < n; i++) {
    pq.push({t[i], i});
  }
  while (pq.size()) {
    int time = pq.top()[0];
    int posi = pq.top()[1];
    pq.pop();
    if (res[posi]) continue;
    res[posi] = time;
    pq.push({time + s[posi], (posi + 1) % n});
  }
  for (auto &i : res) cout << i << '\n';
}
