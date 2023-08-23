#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int a, b;
  cin >> a >> b;
  int ans = 1;
  for (int i = 2; i <= b; i++) {
    int x = b / i;
    if (a <= i * (x - 1) && i * x <= b) {
      ans = i;
    }
  }
  cout << ans << '\n';
}
