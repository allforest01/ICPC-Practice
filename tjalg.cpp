#include <bits/stdc++.h>
using namespace std;

const int N = 10005;

vector<int> adj[N], s;
int num[N], low[N], timer = 0, cnt_ssc = 0;

void chmin(int &a, int b) {
  if (a > b) a = b;
}

void dfs(int i) {
  num[i] = low[i] = ++timer;
  s.push_back(i);
  for (auto &j : adj[i]) {
    if (!num[j]) {
      dfs(j);
      chmin(low[i], low[j]);
    }
    else {
      chmin(low[i], num[j]);
    }
  }
  if (num[i] == low[i]) {
    cnt_ssc++;
    while (true) {
      int t = s.back(); s.pop_back();
      num[t] = low[t] = INT_MAX;
      if (t == i) break;
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
  }
  for (int i = 1; i <= n; i++) {
    if (!num[i]) dfs(i);
  }
  cout << cnt_ssc << '\n';
}
