#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  long long x, y, z, k;
  cin >> x >> y >> z >> k;
  vector<long long> a(x), b(y), c(z);
  for (auto &i : a) cin >> i;
  for (auto &i : b) cin >> i;
  for (auto &i : c) cin >> i;
  sort(a.begin(), a.end(), greater<long long>());
  sort(b.begin(), b.end(), greater<long long>());
  sort(c.begin(), c.end(), greater<long long>());
  set<vector<long long>> vst;
  priority_queue<vector<long long>> pq;
  pq.push({a[0] + b[0] + c[0], 0, 0, 0});
  while (pq.size()) {
    auto i = pq.top(); pq.pop();
    if (vst.count(i)) continue;
    vst.insert(i);
    cout << i[0] << '\n';
    if ((--k) == 0) return 0;
    if (i[1] + 1 < x) pq.push({i[0] - a[i[1]] + a[i[1] + 1], i[1] + 1, i[2], i[3]});
    if (i[2] + 1 < y) pq.push({i[0] - b[i[2]] + b[i[2] + 1], i[1], i[2] + 1, i[3]});
    if (i[3] + 1 < z) pq.push({i[0] - c[i[3]] + c[i[3] + 1], i[1], i[2], i[3] + 1});
  }
}
