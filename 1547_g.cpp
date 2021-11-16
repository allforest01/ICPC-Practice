#include <bits/stdc++.h>
using namespace std;

// 0: no path | 1: only one | 2: more than one | -1: inf

const int N = 400005;

vector<int> adj[N];
int reached[N], in[N], color[N], inStack[N];

void reach(int i) {
  reached[i] = 1;
  for (auto &j : adj[i]) {
    in[j]++;
    if (!reached[j]) reach(j);
  }
}

void dfs(int i) {
  inStack[i] = 1;
  for (auto &j : adj[i]) {
    if (!color[j]) color[j] = color[i];
    else {
      if (!inStack[j] && color[j] != -1) color[j]++;
      else color[j] = -1;
    }
    if ((--in[j]) == 0 && color[j] != -1) dfs(j);
  }
  inStack[i] = 0;
}

void Main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    adj[i].clear();
    reached[i] = in[i] = color[i] = inStack[i] = 0;
  }
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
  }
  reach(1);
  color[1] = 1; dfs(1);
  for (int i = 1; i <= n; i++) {
    if (reached[i] && (!color[i] || in[i])) {
      color[i] = -1;
      for (auto &j : adj[i]) {
        color[j] = -1;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (!reached[i]) {
      cout << 0 << ' ';
    }
    else {
      if (color[1] == -1) color[i] = -1;
      cout << min(2, color[i]) << ' ';
    }
  }
  cout << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
