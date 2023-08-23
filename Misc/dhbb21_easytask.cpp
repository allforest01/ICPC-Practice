#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;

int prim[N + 5], a[N + 5], sum[N + 5];

bool isPrime(int x) {
  if (x < 0) return false;
  return !prim[x];
}

void chmax(int &a, int b) {
  if (a < b) a = b;
}

void chmin(int &a, int b) {
  if (a > b) a = b;
}

int main() {
  prim[0] = prim[1] = 1;
  for (int i = 2; i <= N; i++) if (!prim[i])
  for (int j = i * 2; j <= N; j += i) {
    prim[j] = 1;
  }
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum[i] = a[i] + sum[i - 1];
  }
  int ans = -2e9, mi = 2e9;
  for (int i = 1; i <= n; i++) {
    if (isPrime(i)) {
      chmax(ans, sum[i] - mi);
      chmin(mi, sum[i - 1]);
    }
  }
  cout << ans << '\n';
}