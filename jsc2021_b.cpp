#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m);
  set<int> sa, sb;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sa.insert(a[i]);
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
    sb.insert(b[i]);
  }
  vector<int> c;
  for (int i = 0; i < n; i++) {
    if (!sb.count(a[i])) {
      c.push_back(a[i]);
    }
  }
  for (int i = 0; i < m; i++) {
    if (!sa.count(b[i])) {
      c.push_back(b[i]);
    }
  }
  sort(c.begin(), c.end());
  for (auto &i : c) {
    cout << i << ' ';
  }
  cout << '\n';
}
