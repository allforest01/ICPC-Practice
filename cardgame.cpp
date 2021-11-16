#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  freopen("cardgame.in" , "r", stdin );
  freopen("cardgame.out", "w", stdout);
  int n; cin >> n;
  set<int> s;
  for (int i = 1; i <= n * 2; i++) {
    s.insert(i);
  }
  vector<int> fi, se;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    if (i < n / 2) fi.push_back(x);
    else se.push_back(x);
    s.erase(x);
  }
  sort(fi.begin(), fi.end(), greater<int>());
  sort(se.begin(), se.end());
  int ans = 0;
  for (auto &i : fi) {
    auto it = prev(s.end());
    if (*it > i) {
      ans++;
      s.erase(it);
    }
  }
  for (auto &i : se) {
    auto it = s.begin();
    if (*it < i) {
      ans++;
      s.erase(it);
    }
  }
  cout << ans << '\n';
}
