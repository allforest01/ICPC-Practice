#include <bits/stdc++.h>
using namespace std;

const int N = 3005;

vector<int> adj[N];
int closed[N], vst[N];

void dfs(int i) {
  vst[i] = 1;
  for (auto &j : adj[i]) {
    if (!closed[j] && !vst[j]) dfs(j);
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  freopen("closing.in" , "r", stdin );
  freopen("closing.out", "w", stdout);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    memset(vst, 0, sizeof(vst));
    for (int j = 1; j <= n; j++) {
      if (!closed[j] && !vst[j]) {
        dfs(j);
        break;
      }
    }
    bool ok = 1;
    for (int j = 1; j <= n; j++) {
      if (!closed[j] && !vst[j]) {
        ok = 0;
        break;
      }
    }
    cout << (ok ? "YES" : "NO") << '\n';
    int x; cin >> x;
    closed[x] = 1;
  }
}
