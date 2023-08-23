#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<int> a(n);
  for (auto &i : a) cin >> i;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    set<int> s;
    int sum = 0;
    for (int j = i; j < n; j++) {
      sum += a[j];
      s.insert(a[j]);
      if (sum % (j - i + 1) == 0 && s.count(sum / (j - i + 1))) {
        ans++;
      }
    }
  }
  cout << ans << '\n';
}
