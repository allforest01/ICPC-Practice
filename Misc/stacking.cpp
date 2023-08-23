#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  freopen("stacking.in" , "r", stdin );
  freopen("stacking.out", "w", stdout);
  int n, k;
  cin >> n >> k;
  vector<int> a(n + 2);
  for (int i = 1; i <= k; i++) {
    int u, v;
    cin >> u >> v;
    a[u]++;
    a[v + 1]--;
  }
  for (int i = 1; i <= n; i++) {
    a[i] += a[i - 1];
  }
  sort(a.begin() + 1, a.begin() + n + 1);
  cout << a[(n + 1) / 2] << '\n';
}
