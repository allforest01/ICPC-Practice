#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  map<int,int> a;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    a[x]++;
  }
  vector<int> b(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    ans += a[b[x]];
  }
  cout << ans << '\n';
}
