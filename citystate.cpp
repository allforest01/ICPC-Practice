#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  freopen("citystate.in" , "r", stdin );
  freopen("citystate.out", "w", stdout);
  int n; cin >> n;
  vector<string> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    a[i] = a[i].substr(0, 2);
  }
  map<pair<string,string>,int> mem;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == b[i]) continue;
    ans += mem[make_pair(a[i], b[i])];
    mem[make_pair(b[i], a[i])]++;
  }
  cout << ans << '\n';
}
