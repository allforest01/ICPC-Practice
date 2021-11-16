#include <bits/stdc++.h>
using namespace std;

#define int long long

void Main() {
  int n; cin >> n;
  vector<int> a(n);
  int sum = 0;
  for (auto &i : a) {
    cin >> i;
    sum += i;
  }
  int ans = 0;
  map<int,int> cnt;
  for (auto &i : a) {
    ans += cnt[2 * sum - i * n];
    cnt[i * n]++;
  }
  cout << ans << '\n';
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}