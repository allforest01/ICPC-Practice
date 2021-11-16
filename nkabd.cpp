#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

int divsum[N + 1], dp[N + 1];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  for (int i = 1; i <= N; i++)
  for (int j = i; j <= N; j += i) {
    divsum[j] += i;
  }
  for (int i = 1; i <= N; i++) {
    if (divsum[i] > i * 2) {
      dp[i] = 1;
    }
    dp[i] += dp[i - 1];
  }
  int l, r;
  cin >> l >> r;
  cout << dp[r] - dp[l - 1] << '\n';
}
