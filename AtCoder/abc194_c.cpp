#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  map<int,long long> m;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    m[x]++;
  }
  long long ans = 0;
  for (int i = - 200; i <= 200; i++)
  for (int j = i + 1; j <= 200; j++) {
    ans += (j - i) * (j - i) * (m[i] * m[j]);
  }
  cout << ans << '\n';
}
