#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 100005;

int n, k, cnt;
vector<ll> a[N];
ll tot;

void dfs(int i, int c, ll x, ll sum) {
  if (sum > x) return;
  tot += sum; cnt++;
  if (cnt == k) return;
  if (c + 1 < (int) a[i].size()) {
    dfs(i, c + 1, x, sum - a[i][c] + a[i][c + 1]);
    if (cnt == k) return;
  }
  for (int j = i + 1; j <= n; j++) {
    if ((int) a[j].size() > 1) {
      dfs(j, 1, x, sum + a[j][1]);
      if (cnt == k || sum + a[j][1] > x) return;
    }
  }
}

bool check(ll x, ll sum) {
  tot = sum; cnt = 1;
  if (k == 1) return true;
  for (int i = 1; i <= n; i++) {
    if ((int) a[i].size() > 1) {
      dfs(i, 1, x, sum + a[i][1]);
      if (cnt == k) return true;
    }
  }
  return false;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  freopen("roboherd.in" , "r", stdin );
  freopen("roboherd.out", "w", stdout);
  cin >> n >> k;
  ll sum = 0;
  for (int i = 1; i <= n; i++) {
    int m; cin >> m;
    a[i].resize(m);
    for (auto &j : a[i]) cin >> j;
    sort(a[i].begin(), a[i].end());
    for (int j = 1; j < (int) a[i].size(); j++) {
      a[i][j] -= a[i][0];
    }
    sum += a[i][0];
    a[i][0] = 0;
  }
  sort(a + 1, a + n + 1);
  ll l = sum, r = 1e15, ans = sum;
  while (l <= r) {
    ll x = (l + r) / 2;
    if (check(x, sum)) {
      ans = x;
      r = x - 1;
    }
    else l = x + 1;
  }
  check(ans - 1, sum);
  cout << tot + (k - cnt) * ans << '\n';
}
