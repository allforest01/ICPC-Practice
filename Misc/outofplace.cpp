#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  // freopen("outofplace.in" , "r", stdin );
  // freopen("outofplace.out", "w", stdout);
  int n; cin >> n;
  vector<int> a(n + 1), b(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }
  sort(b.begin() + 1, b.end());
  map<int, int> m;
  int cnt = 0;
  vector<int> v(1);
  for (int i = 1; i <= n; i++) {
    if (a[i] != b[i]) {
      m[b[i]] = ++cnt;
      v.push_back(a[i]);
    }
  }
  for (int i = 1; i < (int) v.size(); i++) {
    v[i] = m[v[i]];
  }
  int ans = 0;
  vector<int> vst(v.size() + 1);
  for (int i = 1; i < (int) v.size(); i++) {
    if (vst[i]) continue;
    int cnt = 0, t = i;
    while (!vst[t]) {
      vst[t] = 1;
      t = v[t];
      cnt++;
    }
    ans += cnt - 1;
  }
  cout << ans << '\n';
}
