#include <bits/stdc++.h>
using namespace std;

void Main() {
  int n; cin >> n;
  vector<array<int,6>> a(n + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 5; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 1; i <= 5 - 1; i++)
  for (int j = i + 1; j <= 5; j++) {
    bool flag = true;
    int cnt1 = 0, cnt2 = 0;
    for (int k = 1; k <= n; k++) {
      if (!a[k][i] && !a[k][j]) {
        flag = false;
        break;
      }
      if (a[k][i] && !a[k][j]) cnt1++;
      if (!a[k][i] && a[k][j]) cnt2++;
    }
    if (!(cnt1 <= n / 2 && cnt2 <= n / 2)) flag = false;
    if (flag) {
      cout << "YES" << '\n';
      return;
    }
  }
  cout << "NO" << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}