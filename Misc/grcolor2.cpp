#include <bits/stdc++.h>
using namespace std;

#define ar    array
#define rank  def_rank
#define left  def_left
#define right def_right

#define white  0
#define red    1
#define blue   2
#define yellow 3
#define green  4

const int N = 100005;

struct Dsu {
  int n; vector<int> root, rank, lf, ri, nd;
  Dsu(int n):
    n(n), root(n + 1), rank(n + 1), lf(n + 1), ri(n + 1), nd(n + 1) {
    for (int i = 1; i <= n; i++) {
      root[i] = lf[i] = ri[i] = i;
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
    if (rank[u] == rank[v]) rank[u]++;
    if (rank[u] < rank[v]) swap(u, v);
    lf[u] = min(lf[u], lf[v]);
    ri[u] = max(ri[u], ri[v]);
    root[v] = u;
    return true;
  }
  int& left(int i) {
    return lf[find(i)];
  }
  int& right(int i) {
    return ri[find(i)];
  }
  int& node(int i) {
    return nd[find(i)];
  }
} dsu(N);

vector<int> adj[N], compAdj[N];
int no_sol = 0; int answer = 0;
int tin[N], tout[N], timer = 0;
int par[N][20], dep[N], col[N];

void dfs(int i, int p) {
  tin[i] = ++timer;
  for (auto &j : adj[i]) {
    if (j != p) {
      par[j][0] = i;
      dep[j] = dep[i] + 1;
      dfs(j, i);
    }
  }
  tout[i] = timer;
}

int lca(int u, int v) {
  if (dep[u] < dep[v]) swap(u, v);
  for (int j = 16; j >= 0; j--) {
    if (dep[par[u][j]] >= dep[v]) {
      u = par[u][j];
    }
  }
  if (u == v) return u;
  for (int j = 16; j >= 0; j--) {
    if (par[u][j] != par[v][j]) {
      u = par[u][j];
      v = par[v][j];
    }
  }
  return par[u][0];
}

bool isAncestor(int u, int v) {
  return tin[v] < tin[u] && tout[v] >= tout[u];
}

void addEdge(int u, int v) {
  if (u == v) return;
  compAdj[u].push_back(v);
  compAdj[v].push_back(u);
}

void addBridge(int u, int l, vector<int> &ver) {
   int p = par[u][0];
  ver.push_back(p);
  addEdge(p, u);
  addEdge(p, l);
}

void blue_coloring(int i, int p) {
  int cnt = 0, last = -1;
  for (auto &j : compAdj[i]) {
    if (j == p) continue;
    blue_coloring(j, i);
    if (col[j] == red || col[j] == white) cnt++;
    last = j;
  }
  if (cnt == 0) {
    if (col[i] != red && last != -1) {
      col[i] = green;
    }
  }
  else if (cnt == 1) {
    if (col[p] == red) {
      col[i] = blue;
      answer++;
    }
  }
  else {
    col[i] = blue;
    answer++;
  }
}

void unique(vector<int> &a) {
  sort(a.begin(), a.end());
  a.resize(unique(a.begin(), a.end()) - a.begin());
}

void solve() {
  int n; cin >> n;
  vector<int> vec(n);
  for (auto &i : vec) {
    cin >> i;
  }
  sort(vec.begin(), vec.end());
  for (auto &i : vec) {
    for (auto &j : adj[i]) {
      auto it = lower_bound(vec.begin(), vec.end(), j);
      if (it != vec.end() && *it == j) {
        puts("-1");
        return;
      }
    }
  }
  sort(vec.begin(), vec.end(), [](int a, int b) {
    return tin[a] < tin[b];
  });
  vector<int> ver;
  for (int i = 0; i < n; i++) {
    dsu.node(i + 1) = vec[i];
    ver.push_back(vec[i]);
  }
  priority_queue<array<int,4>> pq;
  for (int i = 0; i + 1 < n; i++) {
    int l = lca(vec[i], vec[i + 1]);
    pq.push({dep[l], l, i + 1, i + 2});
  }
  while (pq.size()) {
    auto t = pq.top(); pq.pop();
    int l = t[1], u = t[2], v = t[3];
    int nu = dsu.node(u), nv = dsu.node(v);
    if (nu == nv || !dsu.unite(u, v)) continue;
    ver.push_back(l);
    if (isAncestor(nu, l)) addBridge(nu, l, ver); else addEdge(nu, l);
    if (isAncestor(nv, l)) addBridge(nv, l, ver); else addEdge(nv, l);
    dsu.node(u) = l;
    if (dsu.right(u) != n) {
      int ri = dsu.right(u) + 1;
      int luv = lca(l, dsu.node(ri));
      pq.push({dep[luv], luv, u, ri});
    }
    if (dsu.left(u) != 1) {
      int lf = dsu.left(u) - 1;
      int luv = lca(l, dsu.node(lf));
      pq.push({dep[luv], luv, u, lf});
    }
  }
  unique(ver);
  for (auto &i : ver) {
    unique(compAdj[i]);
  }
  for (auto &i : vec) {
    col[i] = red;
  }
  blue_coloring(vec[0], vec[0]);
  printf("%d\n", answer);
  for (auto &i : ver) {
    col[i] = white;
    compAdj[i].clear();
  }
  for (int i = 1; i <= n; i++) {
    dsu.root[i] = dsu.lf[i] = dsu.ri[i] = i;
    dsu.rank[i] = 1; dsu.nd[i] = 0;
  }
  answer = no_sol = 0;
}

int main() {
  int n; scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dep[1] = 1;
  dfs(1, -1);
  for (int j = 1; j <= 16; j++)
  for (int i = 1; i <= n; i++) {
    par[i][j] = par[par[i][j - 1]][j - 1];
  }
  int q; scanf("%d", &q);
  while (q--) solve();
}
