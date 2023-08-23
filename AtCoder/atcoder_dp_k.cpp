#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto &i : a) cin >> i;
  vector<int> dp(k + 1);
  for (int i = 1; i <= k; i++) {
    for (auto &j : a) {
      if (j > i) continue;
      if (dp[i - j] == 0) dp[i] = 1;
    }
  }
  cout << (dp[k] ? "First" : "Second") << '\n';
}