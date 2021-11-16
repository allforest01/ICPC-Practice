#include <bits/stdc++.h>
using namespace std;

void Main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m, 0));
  for (int i = 0; i < m; i += 2) {
    a[0][i] = 1;
  }
  for (int i = 2; i < n; i += 2) {
    a[i][0] = 1;
  }
  for (int i = 2; i < m; i += 2) {
    a[n - 1][i] = 1;
  }
  for (int i = 2; i + 1 < n; i += 2) {
    if (a[i + 1][m - 2] != 1 && a[i + 1][m - 1] != 1) a[i][m - 1] = 1;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << a[i][j];
    }
    cout << '\n';
  }
  cout << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
