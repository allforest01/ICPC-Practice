#include <bits/stdc++.h>
using namespace std;

const int N = 50005;

int a[N], s[N], b[N];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, p;
  cin >> n >> p;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    s[i] = a[i] + s[i - 1];
    if (s[i] < s[b[i - 1]]) b[i] = i;
    else b[i] = b[i - 1];
  }
  int ans = -1;
  {
    int j = n;
    for (int i = n; i >= 1; i--) {
      if (j > i) j = i;
      while (j > 0 && s[i] - s[b[j - 1]] >= p) j = b[j - 1];
      if (s[i] - s[j] >= p) ans = max(ans, i - j);
    }
  }
  cout << ans << '\n';
}