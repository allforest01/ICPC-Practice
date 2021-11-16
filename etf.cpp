#include <bits/stdc++.h>
using namespace std;

const int N = 1000000;

int sieve[N + 1], res[N + 1], mop[N + 1];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  for (int i = 2; i * i <= N; i++) {
    if (sieve[i]) continue;
    for (int j = i * 2; j <= N; j += i) {
      if (!sieve[j]) sieve[j] = i;
    }
  }
  res[1] = 1;
  for (int i = 2; i <= N; i++) {
    if (!sieve[i]) {
      res[i] = i - 1;
      mop[i] = i;
    }
    else if (mop[i / sieve[i]] == sieve[i]) {
      res[i] = i - i / sieve[i];
      mop[i] = sieve[i];
    }
    else {
      int u = i, v = 1;
      while (u % sieve[i] == 0) {
        u /= sieve[i];
        v *= sieve[i];
      }
      res[i] = res[u] * res[v];
      mop[i] = -1;
    }
  }
  int T; cin >> T;
  while (T--) {
    int n; cin >> n;
    cout << res[n] << '\n';
  }
}
