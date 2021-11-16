#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, s;
  cin >> n >> s;
  vector<int> a(n);
  for (auto &i : a) cin >> i;
  sort(a.begin(), a.end());
  int ans = 0;
  while (s >= 100000) {
    s -= a.back();
    ans++;
  }
  vector<int> dp(s + 1, 1e9);
  dp[0] = 0;
  for (auto &i : a) {
    for (int j = i; j <= s; j++) {
      dp[j] = min(dp[j], dp[j - i] + 1);
    }
  }
  cout << dp[s] + ans << '\n';
}
