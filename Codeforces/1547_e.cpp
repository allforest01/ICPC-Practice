#include <bits/stdc++.h>
using namespace std;

#define int long long

void Main() {
  int n, k;
  cin >> n >> k;
  vector<pair<int,int>> a(k + 2);
  a[0    ] = pair<int,int>(0    , 2e9);
  a[k + 1] = pair<int,int>(n + 1, 2e9);
  for (int i = 1; i <= k; i++) {
    cin >> a[i].first;
  }
  for (int i = 1; i <= k; i++) {
    cin >> a[i].second;
  }
  sort(a.begin(), a.end());
  vector<int> res(n + 1, 2e9);
  for (int i = 1, j = 0, t = 2e9; i <= n; i++) {
    while (j + 1 <= k && a[j + 1].first <= i) {
      t = min(t + a[j + 1].first - a[j].first, a[j + 1].second);
      j++;
    }
    res[i] = t + i - a[j].first;
  }
  for (int i = n, j = k + 1, t = 2e9; i >= 1; i--) {
    while (j - 1 >= 1 && a[j - 1].first >= i) {
      t = min(t + a[j].first - a[j - 1].first, a[j - 1].second);
      j--;
    }
    res[i] = min(res[i], t + a[j].first - i);
  }
  for (int i = 1; i <= n; i++) {
    cout << res[i] << ' ';
  }
  cout << '\n';
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
