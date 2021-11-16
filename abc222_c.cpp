#include <bits/stdc++.h>
using namespace std;

const int N = 105;

// G - 0 | C - 1 | P - 2

int tab[3][3] = {
  {0, 1, 0},
  {0, 0, 1},
  {1, 0, 0}
};

int a[N][N], wins[N];

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= 2 * n; i++) {
    for (int j = 1; j <= m; j++) {
      char c; cin >> c;
      if (c == 'G') a[i][j] = 0;
      if (c == 'C') a[i][j] = 1;
      if (c == 'P') a[i][j] = 2;
    }
  }
  vector<array<int,2>> vec;
  for (int i = 1; i <= 2 * n; i++) {
    vec.push_back({0, i});
  }
  for (int j = 1; j <= m; j++) {
    for (int i = 0; i < n; i++) {
      int p1 = vec[i * 2][1], p2 = vec[i * 2 + 1][1];
      wins[p1] += tab[a[p1][j]][a[p2][j]];
      wins[p2] += tab[a[p2][j]][a[p1][j]];
    }
    vec.clear();
    for (int i = 1; i <= 2 * n; i++) {
      vec.push_back({-wins[i], i});
    }
    sort(vec.begin(), vec.end());
  }
  for (auto &i : vec) {
    cout << i[1] << '\n';
  }
}