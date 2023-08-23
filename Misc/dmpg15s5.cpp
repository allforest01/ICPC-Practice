#include <bits/stdc++.h>
using namespace std;

const int N = 10001;

bitset<N> a[N];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int x, y, w, h;
    cin >> x >> y >> w >> h;
    a[x].flip(y);
    a[x + w].flip(y);
    a[x].flip(y + h);
    a[x + w].flip(y + h);
  }
  int ans = 0;
  for (int i = 0; i < n; i++)
  for (int j = 0; j < n; j++) {
    if (i && a[i - 1][j]) a[i].flip(j);
    if (j && a[i][j - 1]) a[i].flip(j);
    if (i && j && a[i - 1][j - 1]) a[i].flip(j);
    if (a[i][j]) ans++;
  }
  cout << ans << '\n';
}
