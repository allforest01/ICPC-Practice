#include <bits/stdc++.h>
using namespace std;

const int N = 3005;

int n, m;
char a[N][N];

struct Dsu {
  int n; vector<int> root, cntc;
  Dsu(int n): n(n), root(n + 1), cntc(n + 1) {
    for (int i = 1; i <= n; i++) {
      root[i] = i;
      cntc[i] = 1;
    }
  }
  int find(int i) {
    if (i == root[i]) return i;
    return root[i] = find(root[i]);
  }
  bool unite(int u, int v) {
    u = find(u); v = find(v);
    if (u == v) return false;
    if (cntc[u] == cntc[v]) cntc[u]++;
    if (cntc[u] < cntc[v]) swap(u, v);
    root[v] = u;
    return true;
  }
};

int id(int r, int c) {
  return m * (r - 1) + (c - 1) + 1;
}

bool chrow(int i, int j) {
  if (a[i][j - 2] == 'R' && a[i][j - 1] == 'G' && a[i][j] == 'W') return true;
  return false;
}

bool chcol(int i, int j) {
  if (a[i - 2][j] == 'R' && a[i - 1][j] == 'G' && a[i][j] == 'W') return true;
  return false;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
  for (int j = 1; j <= m; j++) {
    cin >> a[i][j];
  }
  Dsu dsu(n * m);
  for (int i = 1; i <= n; i++)
  for (int j = 1; j <= m; j++) {
    if (j >= 3 && chrow(i, j)) {
      dsu.unite(id(i, j - 2), id(i, j - 1));
      dsu.unite(id(i, j - 1), id(i, j));
    }
    if (i >= 3 && chcol(i, j)) {
      dsu.unite(id(i - 2, j), id(i - 1, j));
      dsu.unite(id(i - 1, j), id(i, j));
    }
  }
  vector<int> cnt_row(n * m + 1), cnt_col(n * m + 1);
  for (int i = 1; i <= n; i++)
  for (int j = 1; j <= m; j++) {
    if (j >= 3 && chrow(i, j)) {
      cnt_row[dsu.find(id(i, j))]++;
    }
    if (i >= 3 && chcol(i, j)) {
      cnt_col[dsu.find(id(i, j))]++;
    }
  }
  int ans = 0;
  for (int i = 1; i <= n * m; i++) {
    ans += max(cnt_col[i], cnt_row[i]);
  }
  cout << ans << '\n';
}
