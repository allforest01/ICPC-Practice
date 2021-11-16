#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

vector<int> adj[N];
int n, cnt[N];

void dfs(int i, int p) {
  cnt[i] = 1;
  for (auto &j : adj[i]) {
    if (j != p) {
      dfs(j, i);
      cnt[i] += cnt[j];
    }
  }
}

void vst(int i, int p) {
  for (auto &j : adj[i]) {
    if (j == p) continue;
    if (cnt[j] > n / 2) vst(j, i);
  }
  cout << i << '\n';
  exit(0);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1, -1);
  vst(1, -1);
}
