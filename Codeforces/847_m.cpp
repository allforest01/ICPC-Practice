#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<int> a(n);
  for (auto &i : a) cin >> i;
  if (n == 1) {
    cout << a[0] << '\n';
    return 0;
  }
  set<int> s;
  for (int i = 1; i < n; i++) {
    s.insert(a[i] - a[i - 1]);
  }
  if (s.size() == 1) {
    cout << a.back() + *s.begin() << '\n';
  }
  else {
    cout << a.back() << '\n';
  }
}
