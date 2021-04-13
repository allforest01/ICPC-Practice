#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

#define pow abcdef_pow

const int N = 55;
const int MOD = 1e9 + 7;

int pow(int a, int b) {
  if (b == 0) return 1;
  int t = pow(a, b / 2);
  t = (t * t) % MOD;
  if (b % 2) return (t * a) % MOD;
  return t;
}

int mem[N][N];

int comb(int n, int r) {
  if (r == 0) return 1;
  if (r == 1) return n;
  if (r == n) return 1;
  if (mem[n][r] != -1) return mem[n][r];
  return mem[n][r] = (comb(n - 1, r - 1) + comb(n - 1, r)) % MOD;
}

signed main() {
  // freopen("in" , "r", stdin );
  cin.tie(0)->sync_with_stdio(0);
  int n, p;
  cin >> n >> p;
  int odd = 0, even = 0;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    if (x % 2) odd++;
    else even++;
  }
  int ans = 0;
  memset(mem, -1, sizeof(mem));
  for (int i = p; i <= odd; i += 2) {
    (ans += comb(odd, i)) %= MOD;
  }
  (ans *= pow(2, even)) %= MOD;
  cout << ans << endl;
}