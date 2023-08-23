#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int deg[N];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  freopen("planting.in" , "r", stdin );
  freopen("planting.out", "w", stdout);
  int n; cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    deg[u]++;
    deg[v]++;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, deg[i] + 1);
  }
  cout << ans << '\n';
}
