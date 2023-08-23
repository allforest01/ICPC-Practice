#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

vector<int> adj[N], res[N];
int tin[N], low[N], timer = 0;

void chmin(int &a, int b) {
  if (a > b) a = b;
}

void dfs(int i, int p) {
  tin[i] = low[i] = ++timer;
  for (auto &j : adj[i]) {
    if (!low[j]) {
      dfs(j, i);
      if (low[j] > tin[i]) {
        cout << 0 << '\n';
        exit(0);
      }
      chmin(low[i], low[j]);
      res[i].push_back(j);
    }
    else if (j != p) {
      chmin(low[i], tin[j]);
      if (tin[j] < tin[i]) res[i].push_back(j);
    }
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1, -1);
  for (int i = 1; i <= n; i++) {
    for (auto &j : res[i]) {
      cout << i << ' ' << j << '\n';
    }
  }
}
