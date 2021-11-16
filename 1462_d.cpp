#include <bits/stdc++.h>
using namespace std;

void Main() {
  int n; cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int sum = 0, ans = INT_MAX;
  for (int t = 1; t <= n; t++) {
    sum += a[t];
    int i = t + 1, flag = 0, cnt = t - 1;
    while (i <= n) {
      int j = i, s = a[i];
      while (s < sum && j < n) {
        j++;
        s += a[j];
        cnt++;
      }
      if (s != sum) {
        flag = 1;
        break;
      }
      i = j + 1;
    }
    if (!flag) {
      ans = min(ans, cnt);
    }
  }
  cout << ans << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
