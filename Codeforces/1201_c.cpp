#include <bits/stdc++.h>
using namespace std;

long long check(vector<int> &a, long long m) {
  int k = a.size() / 2;
  long long ret = 0;
  for (int i = k; i < a.size(); i++) {
    ret += max(0LL, m - a[i]);
  }
  return ret;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  sort(a.begin(), a.end());
  long long l = 1, r = 2000000000, ans = -1;
  while (l <= r) {
    long long m = (l + r) / 2;
    if (k - check(a, m) >= 0) {
      l = m + 1;
      ans = m;
    }
    else r = m - 1;
  }
  cout << ans << '\n';
}
