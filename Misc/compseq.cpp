#include <bits/stdc++.h>
using namespace std;

#define taskname "COMPSEQ"

void ioset() {
  cin.tie(0)->sync_with_stdio(0);
  if (fopen(taskname".INP", "r")) {
    freopen(taskname".INP", "r", stdin );
    freopen(taskname".OUT", "w", stdout);
  }
}

const int N = 5005;

int a[N], b[N], pa[N], pb[N], dp[N][N];

template<typename T>
void chmin(T &a, T b) {
  if (a > b) a = b;
}

template<typename T>
void chmax(T &a, T b) {
  if (a < b) a = b;
}

void solve() {
  int n, m;
  cin >> n >> m;
  map<int,int> last;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pa[i] = last[a[i]];
    last[a[i]] = i;
  }
  last.clear();
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
    pb[i] = last[b[i]];
    last[b[i]] = i;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++)
  for (int j = 1; j <= m; j++) {
    dp[i][j] = dp[i - 1][j - 1] + 1;
    if (i - pa[i] != j - pb[j]) chmin(dp[i][j], min(i - pa[i], j - pb[j]));
    chmax(ans, dp[i][j]);
  }
  cout << ans << '\n';
}

signed main() {
  ioset();
  solve();
}
