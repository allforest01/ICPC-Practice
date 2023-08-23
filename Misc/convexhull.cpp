#include <bits/stdc++.h>
using namespace std;

#define int long long

#define point pair<int,int>
#define x first
#define y second

int sq(int x) {
  return x * x;
}

int norm(point a) {
  return sq(a.x) + sq(a.y);
}

int cross(point a, point b) {
  return a.x * b.y - a.y * b.x;
}

point operator-(point a, point b) {
  return {a.x - b.x, a.y - b.y};
}

int orien(point a, point b, point c) {
  return cross(b - a, c - a);
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  while ((cin >> n, n)) {
    vector<point> points(n);
    for (int i = 0; i < n; i++) {
      cin >> points[i].x >> points[i].y;
    }
    sort(points.begin(), points.end());
    vector<point> hull;
    for (int i = 0; i < (int) points.size(); i++) {
      while (hull.size() > 1
        && orien(hull[hull.size() - 2], hull.back(), points[i]) <= 0) {
          hull.pop_back();
        }
      hull.push_back(points[i]);
    }
    int t = hull.size();
    for (int i = (int) points.size() - 1; i >= 0; i--) {
      while (hull.size() > t
        && orien(hull[hull.size() - 2], hull.back(), points[i]) <= 0) {
          hull.pop_back();
        }
      hull.push_back(points[i]);
    }
    hull.pop_back();
    hull.resize(unique(hull.begin(), hull.end()) - hull.begin());
    cout << hull.size() << '\n';
    for (auto &i : hull) {
      cout << i.x << ' ' << i.y << '\n';
    }
  }
}
