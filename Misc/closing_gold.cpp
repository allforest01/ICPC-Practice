#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 200005;

vector<int> adj[N];
int opened[N];

struct Dsu {
  int n; vector<int> root, rank;
  Dsu(int n): n(n), root(n + 1), rank(n + 1) {
    for (int i = 1; i <= n; i++) {
      root[i] = i;
      rank[i] = 1;
    }
  }
  int find(int i) {
    if (i == root[i]) return i;
    return root[i] = find(root[i]);
  }
  bool unite(int u, int v) {
    u = find(u); v = find(v);
    if (u == v) return false;
    if (rank[u] < rank[v]) swap(u, v);
    rank[u] += rank[v];
    root[v] = u;
    return true;
  }
  int size(int i) {
    return rank[find(i)];
  }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  freopen("closing.in" , "r", stdin );
  freopen("closing.out", "w", stdout);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<int> v(n);
  for (auto &i : v) cin >> i;
  reverse(v.begin(), v.end());
  Dsu dsu(n);
  vector<int> res;
  for (int i = 0; i < n; i++) {
    opened[v[i]] = 1;
    for (auto &j : adj[v[i]]) {
      if (opened[j]) {
        dsu.unite(v[i], j);
      }
    }
    res.push_back(dsu.size(v[i]) == i + 1);
  }
  reverse(res.begin(), res.end());
  for (auto &i : res) {
    cout << (i ? "YES" : "NO") << '\n';
  }
}
