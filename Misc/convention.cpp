#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, m, c;
int a[N];

bool check(int x) {
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    int j = i;
    while (j + 1 <= n && j - i + 2 <= c && a[j + 1] - a[i] <= x) j++;
    cnt++;
    i = j;
  }
  return cnt <= m;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  freopen("convention.in" , "r", stdin );
  freopen("convention.out", "w", stdout);
  cin >> n >> m >> c;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  int l = 0, r = 1e9, ans = -1;
  while (l <= r) {
    int m = (l + r) / 2;
    if (check(m)) {
      ans = m;
      r = m - 1;
    }
    else l = m + 1;
  }
  cout << ans << '\n';
}
