#include <bits/stdc++.h>
using namespace std;

#define sqr(x) ((x)*(x))
#define int long long

signed main() {
  // cin.tie(0)->sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  vector<pair<int,int>> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].second >> v[i].first;
    v[i].second--;
  }
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  /*for (auto &i : v) {
    cout << "> " << i.first << ' ' << i.second << '\n';
  }*/
  long long sum = 0, diff = 0;
  vector<int> cnt(n);
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
  for (int i = 0; i < k; i++) {
    int f, s;
    tie(f, s) = v[i];
    sum += f;
    cnt[s]++;
    if (cnt[s] == 1) diff++;
    pq.push(v[i]);
  }
  long long sav = sum + sqr(diff), ma = 0;
  for (int i = k; i < n; i++) {
    while (pq.size() && cnt[pq.top().second] == 1) pq.pop();
    if (!pq.size()) break;
    int pf, ps, nf, ns;
    tie(pf, ps) = pq.top();
    tie(nf, ns) = v[i];
    // cout << i << ' ' << cnt[ps] << ' ' << cnt[ns] << '\n';
    if (cnt[ps] > 1 && cnt[ns] == 0) {
      // long long sum_p = sum + sqr(diff);
      long long sum_n = (sum - pf + nf) + sqr(diff + 1);
      // cout << "sum_n = " << sum_n << '\n';
      if (sum_n >= ma) {
        pq.pop();
        // pq.push(v[i]);
        sum = sum - pf + nf;
        cnt[ps]--;
        cnt[ns]++;
        diff++;
        ma = sum_n;
      }
    }
  }
  cout << max(sav, sum + sqr(diff)) << '\n';
}
