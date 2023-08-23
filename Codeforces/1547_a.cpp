#include <bits/stdc++.h>
using namespace std;

void Main() {
  int xa, ya, xb, yb, xf, yf;
  cin >> xa >> ya >> xb >> yb >> xf >> yf;
  int ans = abs(xa - xb) + abs(ya - yb);
  if ((xa == xb && xa == xf && ((ya < yf && yf < yb) || (yb < yf && yf < ya)))
  ||  (ya == yb && ya == yf && ((xa < xf && xf < xb) || (xb < xf && xf < xa)))) {
    ans += 2;
  }
  cout << ans << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
