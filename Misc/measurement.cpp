#include <bits/stdc++.h>
using namespace std;

struct str {
  int time, id, milk;
  str() {}
  str(int t, int id, int m): time(t), id(id), milk(m) {}
  bool operator<(str x) {
    return this->time < x.time;
  }
};

int main() {
  freopen("measurement.in" , "r", stdin );
  freopen("measurement.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<str> v(n);
  map<string, int> name = {
    {"Bessie" , 0},
    {"Elsie"  , 1},
    {"Mildred", 2}
  };
  map<int, int> milks, disp;
  for (int i = 0; i < n; i++) {
    int t, m; string nm;
    cin >> t >> nm >> m;
    v[i] = str(t, name[nm], m);
  }
  int ans = 0;
  sort(v.begin(), v.end());
  for (int i = 0; i < n; i++) {
    milks[v[i].id] += v[i].milk;
    int ma = max(milks[0], max(milks[1], milks[2]));
    int c = 0;
    for (int j = 0; j < 3; j++) {
      int t = (milks[j] == ma);
      if (t != disp[j]) c = 1;
      disp[j] = t;
    }
    ans += c;
  }
  cout << ans << '\n';
}
