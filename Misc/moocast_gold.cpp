#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define sqr(x) ((x)*(x))

struct Dsu {
  vector<int> root, hang;
  Dsu(int n): root(n), hang(n) {
    for (int i = 0; i < n; i++) {
      root[i] = i;
      hang[i] = 1;
    }
  }
  int find(int i) {
    if (i == root[i]) return i;
    return root[i] = find(root[i]);
  }
  bool unite(int u, int v) {
    u = find(u); v = find(v);
    if (u == v) return false;
    if (hang[u] < hang[v]) swap(u, v);
    hang[u] += hang[v];
    root[v] = u;
    return true;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  freopen("moocast.in" , "r", stdin );
  freopen("moocast.out", "w", stdout);
  int n; cin >> n;
  vector<pair<int,int>> a(n);
  for (auto &i : a) {
    cin >> i.first >> i.second;
  }
  vector<vector<ll>> edges;
  for (int i = 0; i + 1 < n; i++)
  for (int j = i + 1; j < n; j++) {
    ll sqr_dist = sqr(a[i].first - a[j].first) + sqr(a[i].second - a[j].second);
    edges.push_back(vector<ll>{sqr_dist, i, j});
  }
  sort(edges.begin(), edges.end());
  ll ans = 0;
  Dsu dsu(n);
  for (auto &i : edges) {
    if (dsu.unite(i[1], i[2])) ans = i[0];
  }
  cout << ans << '\n';
}
