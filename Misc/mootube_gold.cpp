#include <bits/stdc++.h>
using namespace std;

#define ar array

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

int main() {
  cin.tie(0)->sync_with_stdio(0);
  freopen("mootube.in" , "r", stdin );
  freopen("mootube.out", "w", stdout);
  int n, q;
  cin >> n >> q;
  vector<ar<int,3>> edges(n - 1);
  for (auto &e : edges) {
    cin >> e[1] >> e[2] >> e[0];
  }
  sort(edges.begin(), edges.end());
  vector<ar<int,3>> queries(q);
  for (int i = 0; i < q; i++) {
    cin >> queries[i][0] >> queries[i][1];
    queries[i][2] = i;
  }
  sort(queries.begin(), queries.end());
  reverse(queries.begin(), queries.end());
  vector<int> res(q);
  Dsu dsu(n);
  for (auto &i : queries) {
    while (edges.size() && edges.back()[0] >= i[0]) {
      dsu.unite(edges.back()[1], edges.back()[2]);
      edges.pop_back();
    }
    res[i[2]] = dsu.size(i[1]) - 1;
  }
  for (auto &i : res) cout << i << '\n';
}
