#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 * 20 + 5;

bool isPrime[N];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  for (int i = 2; i < N; i++) {
    isPrime[i] = true;
  }
  for (int i = 2; i < N; i++) {
    if (!isPrime[i]) continue;
    for (int j = i * 2; j < N; j += i) {
      isPrime[j] = false;
    }
  }
  int n; cin >> n;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  int ans = 0;
  for (int mask = 0; mask < (1 << n); mask++) {
    int sum0 = 0, sum1 = 0;
    for (int i = 0; i < n; i++) {
      if (mask & (1 << i)) sum1 += a[i];
      else sum0 += a[i];
    }
    if (isPrime[abs(sum1 - sum0)]) {
      ans = max(ans, sum1 - sum0);
    }
  }
  cout << ans << '\n';
}
