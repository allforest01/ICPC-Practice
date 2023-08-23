#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int ans = 0;
  unordered_map<int,int> mem;
  for (int i = 1; i <= n; i++) {
    ans += mem[i - a[i]];
    mem[a[i] + i]++;
  }
  cout << ans << '\n';
}
