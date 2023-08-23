#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  vector<int> a(n);
  for (auto &i : a) cin >> i;
  long long ans = 0, cnt = 0;
  for (int i = 0; i < n; i++) {
    if (i > 0 && a[i] == a[i - 1]) cnt++;
    else cnt = 1;
    ans += cnt;
  }
  cout << ans << '\n';
}
