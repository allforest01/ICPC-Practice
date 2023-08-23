#include <bits/stdc++.h>
using namespace std;

#define int long long

using bigInt = vector<int>;

const int BASE = 1e9;

bigInt sum(bigInt a, bigInt b) {
  while (a.size() < b.size()) a.push_back(0);
  while (b.size() < a.size()) b.push_back(0);
  bigInt ret; ret.resize(a.size());
  int mem = 0;
  for (int i = 0; i < (int) a.size(); i++) {
    mem += a[i] + b[i];
    ret[i] = mem % BASE;
    mem /= BASE;
  }
  if (mem) ret.push_back(mem);
  return ret;
}

void print(bigInt x) {
  for (int i = x.size() - 1; i >= 0; i--) {
    if (i == (int) x.size() - 1) cout << x[i];
    else cout << setw(9) << setfill('0') << x[i];
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  vector<bigInt> dp(101);
  dp[1] = bigInt(1, 1);
  dp[2] = bigInt(1, 2);
  for (int i = 3; i <= 100; i++) {
    dp[i] = sum(dp[i - 1], dp[i - 2]);
  }
  int t; cin >> t;
  while (t--) {
    int x; cin >> x;
    print(dp[x]);
    cout << '\n';
  }
}
