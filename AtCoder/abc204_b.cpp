#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<int> a(n);
  int ans = 0;
  for (auto &i : a) {
    cin >> i;
    ans += max(i - 10, 0);
  }
  cout << ans << '\n';
}
