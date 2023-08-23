#include <bits/stdc++.h>
using namespace std;

void chmax(int &a, int b) {
  if (a < b) a = b;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  freopen("mountains.in" , "r", stdin );
  freopen("mountains.out", "w", stdout);
  int n; cin >> n;
  vector<pair<int,int>> v(n);
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    v[i] = make_pair(x, y);
  }
  sort(v.begin(), v.end(), [](pair<int,int> &a, pair<int,int> &b) {
    int ta = a.first - a.second, tb = b.first - b.second;
    if (ta == tb) {
      return a.second > b.second;
    }
    return ta < tb;
  });
  int ans = n, ma = INT_MIN;
  for (auto &i : v) {
    int t = i.first + i.second;
    if (ma >= t) ans--;
    else ma = t;
  }
  cout << ans << '\n';
}
