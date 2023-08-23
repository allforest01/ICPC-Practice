#include <bits/stdc++.h>
using namespace std;

void Main() {
  int n; cin >> n;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  int ans = a[0];
  for (int i = 1; i < n; i++) {
    ans &= a[i];
  }
  cout << ans << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
