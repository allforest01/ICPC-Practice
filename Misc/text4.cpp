#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef array<ll,2> point;

ll group(point a) {
  if (a[1] < 0) return -1;
  if (a[1] == 0 && a[0] >= 0) return 0;
  return 1;
}

ll cross(point a, point b) {
  return a[0] * b[1] - b[0] * a[1];
}

bool cmp(point a, point b) {
  if (group(a) != group(b)) {
    return group(a) < group(b);
  }
  return cross(a, b) > 0;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<point> v(n);
  for (auto &i : v) {
    cin >> i[0] >> i[1];
  }
  sort(v.begin(), v.end(), cmp);
  for (auto &i : v) {
    cout << i[0] << ' ' << i[1] << '\n';
  }
}
