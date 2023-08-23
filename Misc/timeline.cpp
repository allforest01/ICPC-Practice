#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int res[N], deg[N], vst[N];
vector<array<int,2>> adj[N];

bool chmax(int &a, int b) {
  return a < b ? (a = b, 1) : 0;
}

int dfs(int i) {
  vst[i] = 1;
  for (auto &j : adj[i]) {
    chmax(res[j[1]], res[i] + j[0]);
    if ((--deg[j[1]]) == 0) dfs(j[1]);
  }
}

int main() {
  freopen("timeline.in" , "r", stdin );
  freopen("timeline.out", "w", stdout);
  int n, m, c;
  cin >> n >> m >> c;
  for (int i = 1; i <= n; i++) {
    cin >> res[i];
  }
  for (int i = 1; i <= c; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({w, v});
    deg[v]++;
  }
  for (int i = 1; i <= n; i++) {
    if (deg[i] == 0 && !vst[i]) dfs(i);
  }
  for (int i = 1; i <= n; i++) {
    cout << res[i] << '\n';
  }
}