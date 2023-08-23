#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n + 2);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int c = 0;
  map<int,int> cnt;
  for (int i = 1; i <= k; i++) {
    if (cnt[a[i]] == 0) c++;
    cnt[a[i]]++;
  }
  int ans = c;
  for (int i = k + 1; i <= n; i++) {
    cnt[a[i - k]]--;
    if (cnt[a[i - k]] == 0) c--;
    if (cnt[a[i]] == 0) c++;
    cnt[a[i]]++;
    ans = max(ans, c);
  }
  cout << ans << '\n';
}
