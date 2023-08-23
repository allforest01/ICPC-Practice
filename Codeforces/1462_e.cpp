#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 200005;

int comb3(int n) {
  if (n < 3) return 0;
  int ret = 1;
  for (int i = 1; i <= 3; i++) {
    ret *= (n - 3 + i);
    ret /= i;
  }
  return ret;
}

void Main() {
  int n; cin >> n;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  sort(a.begin(), a.end());
  int ans = 0, r = -1;
  for (int i = 0, j = 0; i < n; i++) {
    if (j < i) j = i;
    while (j + 1 < n && a[j + 1] - a[i] <= 2) j++;
    ans += comb3(j - i + 1);
    if (r >= i) ans -= comb3(r - i + 1);
    r = j;
  }
  cout << ans << '\n';
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
