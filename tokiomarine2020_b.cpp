#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  long long a, v, b, w, t;
  cin >> a >> v >> b >> w >> t;
  long long ba = b - a;
  long long vw = v - w;
  if (b < a) vw = - vw;
  if (vw != 0 && 1 <= ba / vw && abs(ba) <= abs(t * vw)) {
    cout << "YES" << '\n';
  }
  else {
    cout << "NO" << '\n';
  }
}
