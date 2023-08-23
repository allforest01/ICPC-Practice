#include <bits/stdc++.h>
using namespace std;

#define taskname "CUTSEQ"

void ioset() {
  cin.tie(0)->sync_with_stdio(0);
  if (fopen(taskname".INP", "r")) {
    freopen(taskname".INP", "r", stdin );
    freopen(taskname".OUT", "w", stdout);
  }
}

const int N = 205;

int n, a[N], mem[N][N][N];

template<typename T>
void chmax(T &a, T b) {
  if (a < b) a = b;
}

int dp(int l, int r, int k) {
  if (mem[l][r][k] != -1) return mem[l][r][k];
  if (l >  r) return 0;
  if (l == r) return mem[l][r][k] = (k + 1) * (k + 1);
  mem[l][r][k] = dp(l, r - 1, 0) + dp(r, r, k);
  for (int i = l; i <= r - 1; i++) {
    if (a[i] == a[r]) {
      chmax(mem[l][r][k], dp(l, i, k + 1) + dp(i + 1, r - 1, 0));
    }
  }
  return mem[l][r][k];
}

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    char c; cin >> c;
    a[i] = c - '0';
  }
  memset(mem, -1, sizeof(mem));
  cout << dp(1, n, 0) << '\n';
}

signed main() {
  ioset();
  solve();
}
