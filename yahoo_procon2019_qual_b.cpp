#include <bits/stdc++.h>
using namespace std;

int a[5];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  for (int i = 0; i < 3; i++) {
    int u, v;
    cin >> u >> v;
    a[u]++;
    a[v]++;
  }
  bool flag = 0;
  for (int i = 1; i <= 4; i++) {
    if (a[i] > 2) flag = 1;
  }
  if (flag) cout << "NO" << '\n';
  else cout << "YES" << '\n';
}
