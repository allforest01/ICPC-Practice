#include <bits/stdc++.h>
using namespace std;

int sum(int n) {
  return n * (n + 1) / 2;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m);
  for (int i = 0; i < n; i++) {
    a[i] = i + 1;
  }
  for (int i = 0; i < m; i++) {
    b[i] = - i - 1;
  }
  if (n > m) b[m - 1] -= (sum(n) - sum(m));
  else a[n - 1] += (sum(m) - sum(n));
  for (auto &i : a) {
    cout << i << ' ';
  }
  cout << '\n';
  for (auto &i : b) {
    cout << i << ' ';
  }
  cout << '\n';
}
