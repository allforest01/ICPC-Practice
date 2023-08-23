#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("billboard.in" , "r", stdin );
  freopen("billboard.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  vector<int> x(4), y(4);
  for (int i = 0; i < 4; i++) {
    cin >> x[i] >> y[i];
  }
  int area = (x[1] - x[0]) * (y[1] - y[0]);
  if (x[2] <= x[0] && x[1] <= x[3] && y[2] <= y[0] && y[1] <= y[3]) {
    cout << 0 << '\n';
  }
  else if (x[2] <= x[0] && x[1] <= x[3] && y[2] <= y[1] && y[1] <= y[3]) {
    cout << (x[1] - x[0]) * (y[2] - y[0]) << '\n';
  }
  else if (x[2] <= x[0] && x[1] <= x[3] && y[2] <= y[0] && y[0] <= y[3]) {
    cout << (x[1] - x[0]) * (y[1] - y[3]) << '\n';
  }
  else if (y[2] <= y[0] && y[1] <= y[3] && x[2] <= x[1] && x[1] <= x[3]) {
    cout << (y[1] - y[0]) * (x[2] - x[0]) << '\n';
  }
  else if (y[2] <= y[0] && y[1] <= y[3] && x[2] <= x[0] && x[0] <= x[3]) {
    cout << (y[1] - y[0]) * (x[1] - x[3]) << '\n';
  }
  else {
    cout << area << '\n';
  }
}
