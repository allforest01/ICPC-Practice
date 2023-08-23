#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;

int n, m, s, k;
vector<int> adj[N];
int tra[N], vst[N], id = 0;
vector<int> sta;

void dfs(int i, int p) {
  sta.push_back(i);
  vst[i] = ++id;
  for (auto &j : adj[i]) {
    if (vst[j]) {
      if (j != p && vst[j] < vst[i]) {
        sta.push_back(j);
        sta.push_back(i);
      }
      continue;
    }
    dfs(j, i);
    sta.push_back(i);
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m >> s >> k;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (int i = 1; i <= k; i++) {
    cin >> tra[i];
  }
  dfs(s, -1);
  for (int i = 1; i <= k; i++) {
    if (!vst[tra[i]]) {
      cout << "NIE" << '\n';
      return 0;
    }
  }
  cout << "TAK" << '\n';
  cout << sta.size() << ' ';
  for (auto &i : sta) cout << i << ' ';
  cout << '\n';
}
