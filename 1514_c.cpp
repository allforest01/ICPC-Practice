#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 100005;

int n, ans = 0;
int visited[N], inStack[N];

void chmax(int &a, int b) {
  if (a < b) a = b;
}

int modpow(int a, int b, int mod) {
  if (b == 0) return 1;
  int t = modpow(a, b / 2, mod);
  t = (t * t) % mod;
  if (b % 2) return (t * a) % mod;
  return t;
}

int moddiv(int a, int b, int mod) {
  return (a * modpow(b, mod - 2, mod)) % mod;
}

void dfs(int a, int b) {
  visited[b] = inStack[b] = 1;
  if (__gcd(b, n) != 1) return 0;
  dfs(moddiv(a, b, n))
  inStack[b] = 0;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  for (int i = n; i >= 1; i--) {
    chmax(ans, dfs(1, i));
  }
  cout << ans << '\n';
}
