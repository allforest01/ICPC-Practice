#include <bits/stdc++.h>
using namespace std;

#define sqr(x) (x) * (x)

const int N = 5005;

int a[N], b[N];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  int ans = 0;
  for (int i = 0; i < n - 1; i++)
  for (int j = i + 1; j < n; j++) {
    ans = max(ans, sqr(a[i] - a[j]) + sqr(b[i] - b[j]));
  }
  cout << ans << '\n';
}
