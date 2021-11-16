#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  freopen("sleepy.in" , "r", stdin );
  freopen("sleepy.out", "w", stdout);
  int n; cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = n - 1; i >= 1; i--) {
    if (a[i + 1] < a[i]) {
      cout << i << '\n';
      return 0;
    }
  }
  cout << 0 << '\n';
}
