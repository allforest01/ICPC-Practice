#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("guess.in" , "r", stdin );
  freopen("guess.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<vector<string>> v(n);
  for (int i = 0; i < n; i++) {
    string name; int k;
    cin >> name >> k;
    v[i].resize(k);
    for (auto &j : v[i]) cin >> j;
  }
  int ans = 0;
  for (int i = 0; i + 1 < n; i++) {
    set<string> s;
    for (auto &k : v[i]) s.insert(k);
    for (int j = i + 1; j < n; j++) {
      int cal = 0;
      for (auto &k : v[j]) {
        if (s.count(k)) cal++;
      }
      ans = max(ans, cal + 1);
    }
  }
  cout << ans << '\n';
}
