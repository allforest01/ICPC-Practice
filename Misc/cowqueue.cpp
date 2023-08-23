#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  freopen("cowqueue.in" , "r", stdin );
  freopen("cowqueue.out", "w", stdout);
  int n; cin >> n;
  vector<pair<int,int>> a(n);
  for (auto &i : a) {
    cin >> i.first >> i.second;
  }
  sort(a.begin(), a.end());
  int ans = 0;
  for (auto &i : a) {
    ans = max(ans, i.first) + i.second;
  }
  cout << ans << '\n';  
}
