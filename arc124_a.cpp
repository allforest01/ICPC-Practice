#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  vector<int> cnt(n + 1), fix(n + 1);
  for (int i = 1; i <= k; i++) {
    char c; int p;
    cin >> c >> p;
    if (c == 'L') {
      for (int j = n; j >= p; j--) {
        cnt[j]++;
      }
    }
    else if (c == 'R') {
      for (int j = 1; j <= p; j++) {
        cnt[j]++;
      }
    }
    fix[p] = i;
  }
  long long ans = 1;
  for (int i = 1; i <= n; i++) {
    if (!fix[i]) (ans *= cnt[i]) %= 998244353LL;
  }
  cout << ans << '\n';
}
