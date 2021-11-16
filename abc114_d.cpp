#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  map<int,int> div;
  for (int i = 1; i <= n; i++) {
    int t = i;
    for (int j = 2; j * j <= t; j++) {
      while (t % j == 0) {
        div[j]++;
        t /= j;
      }
    }
    if (t > 1) div[t]++;
  }
  // 75 = 3 * 5 * 5 = 15 * 5 = 3 * 25
  int ans = 0;
  for (auto &i : div) {
    if (i.second + 1 >= 75) ans++;
    for (auto &j : div) {
      if (i != j) {
        if (i.second + 1 >= 15 && j.second + 1 >= 5) ans++;
        if (i.second + 1 >= 25 && j.second + 1 >= 3) ans++;
        for (auto &k : div) {
          if (k != i && k != j) {
            if (i.first > j.first) {
              if (i.second + 1 >= 5 && j.second + 1 >= 5 && k.second + 1 >= 3) ans++;
            }
          }
        }
      }
    }
  }
  cout << ans << '\n';
}
