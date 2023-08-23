#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int gold[N], vst[N], mi[N], in[N];
vector<int> adj[N];
int ans = -2e9;

void dfs(int i) {
  vst[i] = 1;
  ans = max(ans, gold[i] - mi[i]);
  mi[i] = min(mi[i], gold[i]);
  for (auto &j : adj[i]) {
    mi[j] = min(mi[j], mi[i]);
    if ((--in[j] == 0)) dfs(j);
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> gold[i];
  }
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    in[v]++;
  }
  for (int i = 1; i <= n; i++) {
    mi[i] = 2e9;
  }
  for (int i = 1; i <= n; i++) {
    if (!vst[i]) dfs(i);
  }
  cout << ans << '\n';
}
