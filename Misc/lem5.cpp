#include <bits/stdc++.h>
using namespace std;

void chmax(int &a, int b) {
  if (a < b) a = b;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<int> a(n);
  for (auto &i : a) cin >> i;
  int ans = 0;
  for (int d = 1; d <= 100; d++) {
    unordered_map<int,int> mem;
    for (auto &i : a) {
      if (mem.count(i - d)) chmax(mem[i], mem[i - d] + 1);
      else chmax(mem[i], 1);
      chmax(ans, mem[i]);
    }
  }
  cout << ans << '\n';
}
