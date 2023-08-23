#include <bits/stdc++.h>
using namespace std;

bool chmax(int &a, int b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(m + 1);
  for (int i = 1; i <= m; i++) {
    cin >> a[i];
  }
  sort(a.begin() + 1, a.end());
  vector<int> s(m + 1);
  for (int i = m; i >= 1; i--) {
    s[i] = a[i] + s[i + 1];
  }
  int ans = 0, val = 0;
  for (int i = 1; i <= 1000000; i++) {
    int p = min((int)(a.end() - lower_bound(a.begin() + 1, a.end(), i)), n);
    if (chmax(ans, i * p)) {
      val = i;
    }
  }
  cout << val << ' ' << ans << '\n';
}