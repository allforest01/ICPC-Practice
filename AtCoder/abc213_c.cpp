#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int h, w, n;
  cin >> h >> w >> n;
  vector<array<int,2>> a(n);
  set<int> set_x, set_y;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    a[i] = {x, y};
    set_x.insert(x);
    set_y.insert(y);
  }
  vector<int> vec_x(set_x.begin(), set_x.end());
  vector<int> vec_y(set_y.begin(), set_y.end());
  for (int i = 0; i < n; i++) {
    a[i][0] = lower_bound(vec_x.begin(), vec_x.end(), a[i][0]) - vec_x.begin() + 1;
    a[i][1] = lower_bound(vec_y.begin(), vec_y.end(), a[i][1]) - vec_y.begin() + 1;
    cout << a[i][0] << ' ' << a[i][1] << '\n';
  }
}
