#include <bits/stdc++.h>
using namespace std;

void Main() {
  int W, H, x1, y1, x2, y2, w2, h2;
  cin >> W >> H >> x1 >> y1 >> x2 >> y2 >> w2 >> h2;
  int w1 = x2 - x1, h1 = y2 - y1;
  int ans = INT_MAX;
  if (w1 + w2 <= W) {
    if (x1 >= w2) ans = 0;
    else ans = min(ans, abs(x1 - w2));
    if (x2 <= W - w2) ans = 0;
    else ans = min(ans, abs(x2 - (W - w2)));
  }
  if (h1 + h2 <= H) {
    if (y1 >= h2) ans = 0;
    else ans = min(ans, abs(y1 - h2));
    if (y2 <= H - h2) ans = 0;
    else ans = min(ans, abs(y2 - (H - h2)));
  }
  if (ans == INT_MAX) ans = -1;
  cout << ans << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
