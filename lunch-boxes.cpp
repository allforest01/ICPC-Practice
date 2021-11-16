#include <bits/stdc++.h>
using namespace std;

void Main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(m);
  for (auto &i : a) {
    cin >> i;
  }
  sort(a.begin(), a.end());
  for (int i = 0; i < m; i++) {
    n -= a[i];
    if (n < 0) {
      cout << i << '\n';
      return;
    }
  }
  cout << m << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
