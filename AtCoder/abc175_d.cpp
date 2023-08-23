#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  vector<int> per(n + 1), score(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> per[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> score[i];
  }
  vector<int> vst(n + 1);
  vector<vector<int>> cycs;
  for (int i = 1; i <= n; i++) {
    if (!vst[i]) {
      vector<int> cyc;
      int t = i;
      while (!vst[t]) {
        vst[t] = 1;
        cyc.push_back(t);
        t = per[t];
      }
      cycs.push_back(cyc);
    }
  }
  int ans = LLONG_MIN;
  for (auto &cyc : cycs) {
    int sz = cyc.size();
    vector<int> sum(sz * 2);
    for (int i = 0; i < sz * 2; i++) {
      sum[i] = score[cyc[i % sz]];
      if (i > 0) sum[i] += sum[i - 1];
    }
    for (int i = 0; i < sz; i++)
    for (int j = i; j < sz * 2; j++) {
      int len = j - i + 1;
      if (len > k) continue;
      int cal = max((k - len) / sz * sum[sz - 1], 0LL) + sum[j];
      if (i > 0) cal -= sum[i - 1];
      ans = max(ans, cal);
    }
  }
  cout << ans << '\n';
}
