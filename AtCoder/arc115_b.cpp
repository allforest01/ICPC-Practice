#include <bits/stdc++.h>
using namespace std;

const int N = 505;

int mt[N][N], a[N], b[N];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  for (int i = 1; i <= n; i++)
  for (int j = 1; j <= n; j++) {
    cin >> mt[i][j];
  }
  for (int i = 2; i <= n; i++)
  for (int j = 2; j <= n; j++) {
    if (mt[i][j] != mt[i - 1][j] + mt[i][j - 1] - mt[i - 1][j - 1]) {
      cout << "No" << '\n';
      return 0;
    }
  }
  for (int i = 1; i <= n; i++) {
    b[i] = mt[1][i];
  }
  int Min = INT_MAX;
  for (int i = 1; i <= n; i++) {
    a[i] = mt[i][i] - b[i];
    Min = min(Min, a[i]);
  }
  if (Min < 0) {
    for (int i = 1; i <= n; i++) {
      a[i] += -Min;
    }
    for (int i = 1; i <= n; i++) {
      b[i] = mt[i][i] - a[i];
    }
  }
  cout << "Yes" << '\n';
  for (int i = 1; i <= n; i++) {
    cout << a[i] << ' ';
  }
  cout << '\n';
  for (int i = 1; i <= n; i++) {
    cout << b[i] << ' ';
  }
  cout << '\n';
}
