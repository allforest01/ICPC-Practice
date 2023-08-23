#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  int ans = 0;
  vector<int> a(2 * n + 1);
  for (auto &i : a) {
    cin >> i;
    ans ^= i;
  }
  multiset<int> s;
  for (int i = 1; i <= 2 * n + 1; i++) {
    int x; cin >> x;
    s.insert(x);
    ans ^= x;
  }
  for (auto &i : a) {
    auto it = s.find(i ^ ans);
    if (it != s.end()) s.erase(it);
  }
  cout << (s.size() == 0 ? ans : - 1) << '\n';
}
