#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  freopen("highcard.in" , "r", stdin );
  freopen("highcard.out", "w", stdout);
  int n; cin >> n;
  set<int> elsie, bessie;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    elsie.insert(x);
  }
  for (int i = 1; i <= n * 2; i++) {
    if (!elsie.count(i)) {
      bessie.insert(i);
    }
  }
  int ans = 0;
  for (auto &i : elsie) {
    auto it = bessie.upper_bound(i);
    if (it == bessie.end()) break;
    bessie.erase(it);
    ans++;
  }
  cout << ans << '\n';
}
