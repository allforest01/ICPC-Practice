#include <bits/stdc++.h>
using namespace std;

void chmin(int &a, int b) {
  if (a > b) a = b;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  int ma = 0;
  map<int,int> cnt;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    ma = max(ma, x);
    cnt[x]++;
  }
  chmin(cnt[0], k);
  long long ans = cnt[0];
  for (int i = 1; i <= ma; i++) {
    chmin(cnt[i], cnt[i - 1]);
    ans += (long long) cnt[i];
  }
  cout << ans << '\n';
}
