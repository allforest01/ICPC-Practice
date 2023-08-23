#include <bits/stdc++.h>
using namespace std;

bool in(int x, int l, int r) {
  if (l <= x && x <= r) return true;
  return false;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<int> v(n);
  for (auto &i : v) cin >> i;
  v.push_back(- 1e9 - 1e4);
  v.push_back(  1e9 + 1e4);
  sort(v.begin(), v.end());
  int a, b;
  cin >> a >> b;
  int max_d = 0, ans = -1;
  for (int i = 0; i + 1 < v.size(); i++) {
    int c1 = in(v[i], a, b), c2 = in(v[i + 1], a, b);
    if (c1 || c2 || (v[i] < a && v[i] > b)) {
      int m = (v[i] + v[i + 1]) / 2;
      if (m < a) m = a;
      if (m > b) m = b;
      if (m % 2 == 0) {
        if (m > a) m--;
        else if (m < b) m++;
      }
      int dist = min(abs(m - v[i]), abs(m - v[i + 1]));
      if (max_d < dist) {
        max_d = dist;
        ans = m;
      }
    }
  }
  cout << ans << '\n';
}
