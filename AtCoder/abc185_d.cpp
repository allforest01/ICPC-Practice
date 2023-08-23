#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<int> v(m + 2);
  v[0] = 0; v[m + 1] = n + 1;
  for (int i = 1; i <= m; i++) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  int mi = INT_MAX;
  for (int i = 1; i < v.size(); i++) {
    if (v[i] - v[i - 1] > 1) {
      mi = min(mi, v[i] - v[i - 1] - 1);
    }
  }
  int ans = 0;
  for (int i = 1; i < v.size(); i++) {
    ans += (v[i] - v[i - 1] - 1 + mi - 1) / mi;
  }
  cout << ans << '\n';
}
