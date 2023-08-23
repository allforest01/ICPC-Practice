#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

vector<array<int,2>> adj[N];
int col[N], vst[N];

int dfs(int i, int c, int v) {
  col[i] = c;
  vst[i] = v;
  int ret = 0;
  for (auto &j : adj[i]) {
    if (vst[j[0]] == v) {
      if (col[j[0]] != j[1] ^ c) return -1e9;
      continue;
    }
    ret += dfs(j[0], j[1] ^ c, v);
    if (ret < 0) return ret;
  }
  return c + ret;
}

void Main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v; string s;
    cin >> u >> v >> s;
    int t = (s == "imposter");
    adj[u].push_back({v, t});
    adj[v].push_back({u, t});
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (!vst[i]) {
      ans += max(
        dfs(i, 0, 1),
        dfs(i, 1, 2)
      );
      if (ans < 0) break;
    }
  }
  if (ans < 0) ans = -1;
  cout << ans << '\n';
  for (int i = 1; i <= n; i++) {
    adj[i].clear();
    col[i] = vst[i] = 0;
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}