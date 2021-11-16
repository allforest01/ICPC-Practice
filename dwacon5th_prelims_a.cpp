#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<int> a(n);
  int avr = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    avr += a[i];
    a[i] *= n;
  }
  int mi = INT_MAX, ans = -1;
  for (int i = 0; i < n; i++) {
    int t = abs(avr - a[i]);
    if (mi > t) {
      mi = t;
      ans = i;
    }
  }
  cout << ans << '\n';
}
