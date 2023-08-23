#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n + 1), s(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    s[i] = a[i] + s[i - 1];
  }
  long long ans = 0;
  map<int,int> mem;
  for (int i = 1; i <= n; i++) {
    mem[s[i - 1]]++;
    ans += mem[s[i] - k];
  }
  cout << ans << '\n';
}
