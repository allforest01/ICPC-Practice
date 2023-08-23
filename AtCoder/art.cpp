#include <bits/stdc++.h>
using namespace std;

#define left def_left
#define right def_right

const int N = 1000005;

int a[1005][1005], sum[1005][1005];
int left[N], up[N], down[N], right[N], ans[N];

void chmin(int &a, int b) {
  if (a > b) a = b;
}

void chmax(int &a, int b) {
  if (a < b) a = b;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  freopen("art.in" , "r", stdin );
  freopen("art.out", "w", stdout);
  memset(left, 0x3f, sizeof(left));
  memset(up  , 0x3f, sizeof(up  ));
  int n; cin >> n;
  for (int i = 1; i <= n; i++)
  for (int j = 1; j <= n; j++) {
    int c; cin >> c;
    a[i][j] = c;
    chmin(left[c] , j);
    chmax(right[c], j);
    chmin(up[c]   , i);
    chmax(down[c] , i);
  }
  int seen = 0;
  for (int i = 1; i <= n * n; i++) {
    if (left[i] == 0x3f3f3f3f) continue;
    seen++;
    sum[up[i]      ][left[i]     ]++;
    sum[up[i]      ][right[i] + 1]--;
    sum[down[i] + 1][left[i]     ]--;
    sum[down[i] + 1][right[i] + 1]++;
  }
  for (int i = 1; i <= n; i++)
  for (int j = 1; j <= n; j++) {
    sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
    if (sum[i][j] > 1) ans[a[i][j]] = 1;
  }
  int cnt = 0;
  for (int i = 1; i <= n * n; i++) {
    if (!ans[i]) cnt++;
  }
  cout << cnt - (seen == 1) << '\n';
}
