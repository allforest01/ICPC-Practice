#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &a, int n, int m, int x) {
  vector<int> cnt(n);
  for (int i = 0; i < m; i++) {
    cnt[a[i]]++;
  }
  for (int i = 0; i < x; i++) {
    if (!cnt[i]) return 0;
  }
  for (int i = m; i < n; i++) {
    cnt[a[i - m]]--;
    cnt[a[i]]++;
    if (a[i - m] < x && !cnt[a[i - m]]) return 0;
  }
  return 1;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  int l = 0, r = n, ans = -1;
  while (l <= r) {
    int x = (l + r) / 2;
    if (check(a, n, m, x)) {
      l = x + 1;
      ans = x;
    }
    else r = x - 1;
  }
  cout << ans << '\n';
}
