#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(),(x).end()

const int N = 805;

vector<int> adj[N], stk, scc_adj[N];
int scc_n = 0, scc[N], scc_inDeg[N];
int tin[N], low[N], timer = 0;

void chmin(int &a, int b) {
  if (a > b) a = b;
}

void dfs(int i) {
  tin[i] = low[i] = ++timer;
  stk.push_back(i);
  for (auto &j : adj[i]) {
    if (!tin[j]) {
      dfs(j);
      chmin(low[i], low[j]);
    }
    else {
      chmin(low[i], tin[j]);
    }
  }
  if (tin[i] == low[i]) {
    scc_n++;
    int u = -1;
    do {
      u = stk.back(); stk.pop_back();
      tin[u] = low[u] = 2e9;
      scc[u] = scc_n;
    }
    while (u != i);
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
  }
  for (int i = 1; i <= n; i++) {
    if (!tin[i]) dfs(i);
  }
  for (int i = 1; i <= n; i++) {
    for (auto &j : adj[i]) {
      if (scc[i] == scc[j]) continue;
      scc_adj[scc[i]].push_back(scc[j]);
    }
  }
  for (int i = 1; i <= scc_n; i++) {
    sort(all(scc_adj[i]));
    scc_adj[i].resize(unique(all(scc_adj[i])) - scc_adj[i].begin());
  }
  for (int i = 1; i <= scc_n; i++) {
    for (auto &j : scc_adj[i]) {
      scc_inDeg[j]++;
    }
  }
  int ans = 0;
  for (int i = 1; i <= scc_n; i++) {
    if (scc_inDeg[i] == 0) ans++;
  }
  cout << ans << '\n';
}
