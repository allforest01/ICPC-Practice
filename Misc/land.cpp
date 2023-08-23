#include <bits/stdc++.h>
using namespace std;

#define taskname "LAND"

#define int long long

void ioset() {
  cin.tie(0)->sync_with_stdio(0);
  if (fopen(taskname".INP", "r")) {
    freopen(taskname".INP", "r", stdin );
    freopen(taskname".OUT", "w", stdout);
  }
}

const int N = 105;

int n, x, y, z;
int a[N], b[N];
int dp[N * 10][N * 10];

template<typename T>
void chmin(T &a, T b) {
  if (a > b) a = b;
}

void solve() {
  cin >> n >> x >> y >> z;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
  }
  vector<int> va(1), vb(1);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= a[i]; j++) va.push_back(i);
    for (int j = 1; j <= b[i]; j++) vb.push_back(i);
  }
  int na = va.size() - 1, nb = vb.size() - 1;
  memset(dp, 0x3f, sizeof(dp));
  dp[0][0] = 0;
  for (int i = 1; i <= na; i++) {
    dp[i][0] = y * i;
  }
  for (int j = 1; j <= nb; j++) {
    dp[0][j] = x * j;
  }
  for (int i = 1; i <= na; i++)
  for (int j = 1; j <= nb; j++) {
    chmin(dp[i][j], dp[i - 1][j] + y);
    chmin(dp[i][j], dp[i][j - 1] + x);
    chmin(dp[i][j], dp[i - 1][j - 1] + z * abs(va[i] - vb[j]));
  }
  cout << dp[na][nb] << '\n';
}

signed main() {
  ioset();
  solve();
}
