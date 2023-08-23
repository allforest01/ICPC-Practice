#include <bits/stdc++.h>
using namespace std;

int is_intersect(int a, int b, int c, int d) {
  return min(b, d) - max(a, c) >= 0;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<int> l(n), r(n);
  for (int i = 0; i < n; i++) {
    int t, a, b;
    cin >> t >> a >> b;
    a *= 2;
    b *= 2;
    if (t == 1) {
      l[i] = a;
      r[i] = b;
    }
    else if (t == 2) {
      l[i] = a;
      r[i] = b - 1;
    }
    else if (t == 3) {
      l[i] = a + 1;
      r[i] = b;
    }
    else if (t == 4) {
      l[i] = a + 1;
      r[i] = b - 1;
    }
  }
  int ans = 0;
  for (int i = 0; i + 1 < n; i++)
  for (int j = i + 1; j < n; j++) {
    if (is_intersect(l[i], r[i], l[j], r[j])) ans++;
  }
  cout << ans << '\n';
}
