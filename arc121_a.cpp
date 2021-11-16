#include <bits/stdc++.h>
using namespace std;

#define sqr(x) ((x)*(x))

long long dist(vector<long long> a, vector<long long> b) {
  return max(abs(a[0] - b[0]), abs(a[1] - b[1]));
}

int main() {
  // freopen("out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<vector<long long>> a(n);
  for (int i = 0; i < n; i++) {
    long long x, y;
    cin >> x >> y;
    a[i] = {x, y, i};
  }
  set<vector<long long>> s;
  sort(a.begin(), a.end());
  s.insert(a[0]);
  s.insert(a[1]);
  s.insert(a[n - 1]);
  s.insert(a[n - 2]);
  sort(a.begin(), a.end(), [](vector<long long> &a, vector<long long> &b) {
    return a[1] < b[1];
  });
  s.insert(a[0]);
  s.insert(a[1]);
  s.insert(a[n - 1]);
  s.insert(a[n - 2]);
  vector<vector<long long>> v(s.begin(), s.end());
  vector<long long> vDist;
  for (int i = 0; i + 1 < v.size(); i++)
  for (int j = i + 1; j < v.size(); j++) {
    vDist.push_back(dist(v[i], v[j]));
  }
  sort(vDist.begin(), vDist.end(), greater<long long>());
  cout << setprecision(10) << fixed << vDist[1] << '\n';
}
