#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  vector<array<int,3>> a(n);
  for (auto &i : a) {
    cin >> i[0];
  }
  for (auto &i : a) {
    cin >> i[1];
  }
  for (int i = 0; i < n; i++) {
    a[i][2] = i + 1;
  }
  sort(a.begin(), a.end(), [](array<int,3> a, array<int,3> b) {
    int sa = max(a[0] + b[0], a[0] + a[1]) + b[1];
    int sb = max(b[0] + a[0], b[0] + b[1]) + a[1];
    return sa < sb;
  });
  vector<int> s(n), t(n);
  s[0] = a[0][0];
  t[0] = a[0][0] + a[0][1];
  for (int i = 1; i < n; i++) {
    s[i] = s[i - 1] + a[i][0];
    t[i] = max(s[i], t[i - 1]) + a[i][1];
  }
  cout << t[n - 1] << '\n';
  for (auto &i : a) cout << i[2] << ' ';
  cout << '\n';
}
