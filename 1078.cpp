#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 1e9 + 7;

const int N = 1e6 + 1;

int mem_fact[N * 2];
map<int,int> bit[N];

int mod(int n) {
  return (n % MOD + MOD) % MOD;
}

int fact(int n) {
  if (n == 0) return 1;
  if (mem_fact[n]) return mem_fact[n];
  return mem_fact[n] = mod(n * fact(n - 1));
}

int modpow(int a, int b) {
  if (b == 0) return 1;
  int t = modpow(a, b / 2);
  t = (t * t) % MOD;
  if (b % 2) return (t * a) % MOD;
  return t;
}

int modinv(int n) {
  return modpow(n, MOD - 2);
}

int get(int pi, int pj) {
  int v = 0;
  for (int i = pi; i > 0; i -= i & -i)
  for (int j = pj; j > 0; j -= j & -j) {
    (v += bit[i][j]) %= MOD;
  }
  return v;
}

void update(int pi, int pj, int v) {
  for (int i = pi; i < N; i += i & -i)
  for (int j = pj; j < N; j += j & -j) {
    (bit[i][j] += v) %= MOD;
  }
}

int cal(int u, int v) {
  u--; v--;
  return mod(mod(fact(u + v) * modinv(fact(u))) * modinv(fact(v)));
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<pair<int,int>> v(m);
  for (auto &i : v) {
    cin >> i.first >> i.second;
  }
  sort(v.begin(), v.end());
  v.push_back(make_pair(n, n));
  vector<int> res(m + 1);
  for (int i = 0; i <= m; i++) {
    int ix = v[i].first, iy = v[i].second;
    res[i] = cal(ix, iy);
    for (int j = 0; j < i; j++) {
      int jx = v[j].first, jy = v[j].second;
      if (ix >= jx && iy >= jy) {
        res[i] = mod(res[i] - res[j] * cal(ix - jx + 1, iy - jy + 1));
      }
    }
  }
  cout << res[m] << '\n';
}
