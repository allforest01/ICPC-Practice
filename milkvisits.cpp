#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

vector<int> adj[N];
char a[N];
int par[N][25], dep[N];
int h[N][25], g[N][25];

void chmax(int &a, int b) {
  if (a < b) a = b;
}

void dfs(int i) {
  if (a[i] == 'H') h[i][0] = 1;
  if (a[i] == 'G') g[i][0] = 1;
  for (auto &j : adj[i]) {
    if (j != par[i][0]) {
      par[j][0] = i;
      dep[j] = dep[i] + 1;
      dfs(j);
    }
  }
}

pair<int,int> get(int u, int v) {
  int bh = 0, bg = 0;
  if (dep[u] < dep[v]) swap(u, v);
  for (int j = 20; j >= 0; j--) {
    if (dep[par[u][j]] >= dep[v]) {
      chmax(bh, h[u][j]);
      chmax(bg, g[u][j]);
      u = par[u][j];
    }
  }
  if (u == v) {
    chmax(bh, h[u][0]);
    chmax(bg, g[u][0]);
    return make_pair(bh, bg);
  }
  for (int j = 20; j >= 0; j--) {
    if (par[u][j] != par[v][j]) {
      chmax(bh, max(h[u][j], h[v][j]));
      chmax(bg, max(g[u][j], g[v][j]));
      u = par[u][j];
      v = par[v][j];
    }
  }
  chmax(bh, max(h[u][1], h[v][1]));
  chmax(bg, max(g[u][1], g[v][1]));
  return make_pair(bh, bg);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  freopen("milkvisits.in" , "r", stdin );
  freopen("milkvisits.out", "w", stdout);
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1);
  for (int j = 1; j <= 20; j++)
  for (int i = 1; i <= n; i++) {
    int p = par[i][j - 1];
    par[i][j] = par[p][j - 1];
    h[i][j] = max(h[i][j - 1], h[p][j - 1]);
    g[i][j] = max(g[i][j - 1], g[p][j - 1]);
  }
  /*for (int i = 1; i <= n; i++) {
    cerr << "i = " << i << '\n';
    for (int j = 0; j <= 3; j++) {
      cerr << h[i][j] << ' ';
    }
    cerr << '\n';
  }*/
  while (q--) {
    int u, v; char c;
    cin >> u >> v >> c;
    auto g = get(u, v);
    if ((c == 'H' && g.first) || (c == 'G' && g.second)) {
      cout << 1;
    }
    else {
      cout << 0;
    }
  }
  cout << '\n';
}
