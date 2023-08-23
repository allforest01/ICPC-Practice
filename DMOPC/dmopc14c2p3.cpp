#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<long long> saws(n);
  for (auto &i : saws) cin >> i;
  sort(saws.begin(), saws.end());
  vector<long long> logs(n);
  for (auto &i : logs) cin >> i;
  sort(logs.begin(), logs.end(), greater<int>());
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans += saws[i] * logs[i];
  }
  cout << ans << '\n';
}
