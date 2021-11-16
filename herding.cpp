#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  freopen("herding.in" , "r", stdin );
  freopen("herding.out", "w", stdout);
  int a[3];
  cin >> a[0] >> a[1] >> a[2];
  int ab = a[1] - a[0], bc = a[2] - a[1];
  int ma = max(ab - 1, bc - 1);
  int mi = -1;
  if (ab == 1 && bc == 1) mi = 0;
  else if (ab == 2 || bc == 2) mi = 1;
  else mi = 2;
  cout << mi << '\n' << ma << '\n';
}
