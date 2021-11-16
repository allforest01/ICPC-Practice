#include <bits/stdc++.h>
using namespace std;

#define int long long

void Main() {
  int n; cin >> n;
  vector<vector<int>> adj(n + 1);
  vector<int> in(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> in[i];
    for (int j = 1; j <= in[i]; j++) {
      int x; cin >> x;
      adj[x].push_back(i);
    }
  }
  set<int> s;
  for (int i = 1; i <= n; i++) {
    if (in[i] == 0) s.insert(i);
  }
  int p = 1, cnt = 0, ans = 1;
  while (s.size()) {
    auto it = s.lower_bound(p);
    if (it == s.end()) {
      if (p == 1) {
        cout << -1 << '\n';
        return;
      }
      p = 1;
      ans++;
    }
    else {
      int i = *it;
      cnt++;
      for (auto &j : adj[i]) {
        in[j]--;
        if (in[j] == 0) s.insert(j);
      }
      p = i;
      s.erase(i);
    }
  }
  cout << (cnt == n ? ans : -1) << '\n';
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}