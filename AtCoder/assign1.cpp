#include <bits/stdc++.h>
using namespace std;

const int N = 605;
const int A = 300;

int n, a[N][N];
vector<int> adj[N];
int capa[N][N], flow[N][N], level[N];

bool bfs(int s, int t) {
  memset(level, 0, sizeof(level));
  queue<int> q; q.push(s); level[s] = 1;
  bool flag = false;
  while (q.size()) {
    int i = q.front(); q.pop();
    if (i == t) flag = true;
    for (auto &j : adj[i]) {
      if (capa[i][j] - flow[i][j] >= 1 && !level[j]) {
        level[j] = level[i] + 1;
        q.push(j);
      }
    }
  }
  return flag;
}

bool dfs(int i, int t) {
  if (i == t) return true;
  for (auto &j : adj[i]) {
    if (capa[i][j] - flow[i][j] >= 1 && level[j] == level[i] + 1) {
      flow[i][j]++;
      flow[j][i]--;
      if (dfs(j, t)) return true;
      flow[i][j]--;
      flow[j][i]++;
    }
  }
  return false;
}

bool check(int x) {
  for (int i = 0; i < N; i++) {
    adj[i].clear();
  }
  memset(capa, 0, sizeof(capa));
  memset(flow, 0, sizeof(flow));
  for (int i = 1; i <= n; i++)
  for (int j = 1; j <= n; j++) {
    if (a[i][j] <= x) {
      adj[i].push_back(j + A);
      adj[j + A].push_back(i);
      capa[i][j + A] = 1;
    }
  }
  for (int i = 1; i <= n; i++) {
    adj[0].push_back(i);
    adj[i].push_back(0);
    capa[0][i] = 1;
  }
  for (int j = 1; j <= n; j++) {
    adj[j + A].push_back(600);
    adj[600].push_back(j + A);
    capa[j + A][600] = 1;
  }
  int ans = 0;
  while (bfs(0, 600)) {
    while (dfs(0, 600)) ans++;
  }
  return (ans == n);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++)
  for (int j = 1; j <= n; j++) {
    cin >> a[i][j];
  }
  int l = 0, r = INT_MAX, ans = -1;
  while (l <= r) {
    int x = l + (r - l) / 2;
    if (check(x)) {
      ans = x;
      r = x - 1;
    }
    else l = x + 1;
  }
  cout << ans << '\n';
}
