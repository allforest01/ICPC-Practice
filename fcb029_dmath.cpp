#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
  int a, b, c, n;
  cin >> a >> b >> c >> n;
  a %= c;
  b %= c;
  vector<int> v(1, 0);
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    x %= c;
    for (int j = 0; j < y; j++) {
      v.push_back(x);
    }
  }
  n = v.size() - 1;
  vector<set<array<int,2>>> dp(n + 1);
  dp[0].insert({a, b});
  for (int i = 1; i <= n; i++) {
    for (auto &j : dp[i - 1]) {
      dp[i].insert(j);
      dp[i].insert({((ll)j[0] * v[i]) % c, j[1]});
      dp[i].insert({j[0], ((ll)j[1] * v[i]) % c});
    }
  }
  for (auto &i : dp[n]) {
    if ((i[0] + i[1]) % c == 0) {
      cout << "YES" << '\n';
      return;
    }
  }
  cout << "NO" << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) solve();
}
