#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, q;
  cin >> n >> q;
  vector<array<int,20>> sp(n);
  for (int i = 0; i < n; i++) {
    cin >> sp[i][0];
  }
  for (int j = 1; j < 20; j++) {
    for (int i = 0; i + (1 << j) - 1 < n; i++) {
      sp[i][j] = min(sp[i][j - 1], sp[i + (1 << (j - 1))][j - 1]);
      // cout << sp[i][j] << " \n"[i + (1 << j) == n];
    }
  }
  auto getMin = [&sp](int l, int r)->int {
    int len = r - l + 1, t = 0;
    while ((1 << (t + 1)) <= len) t++;
    return min(sp[l][t], sp[r - (1 << t) + 1][t]);
  };
  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << getMin(l, r - 1) << '\n';
  }
}
