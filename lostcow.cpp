#include <bits/stdc++.h>
using namespace std;

bool in(int x, int l, int r) {
  if (l > r) swap(l, r);
  if (l <= x && x <= r) return true;
  return false;
}

int main() {
  freopen("lostcow.in" , "r", stdin );
  freopen("lostcow.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  int x, y;
  cin >> x >> y;
  y -= x;
  int ans = 0;
  for (int i = 1; true; i *= -2) {
    if (in(y, i / -2, i)) {
      ans += abs(y - (i / -2));
      break;
    }
    else ans += abs(i - (i / -2));
  }
  cout << ans << '\n';
}
