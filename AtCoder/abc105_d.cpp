#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  map<int,int> d;
  long long s = 0, ans = 0;
  d[0] = 1;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    s += x;
    s %= m;
    ans += d[s];
    d[s]++;
  }
  cout << ans << '\n';
}
