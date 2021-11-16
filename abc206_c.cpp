#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  map<int,int> cnt;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    ans += cnt[x];
    cnt[x]++;
  }
  cout << (long long) n * (n - 1) / 2 - ans << '\n';
}
