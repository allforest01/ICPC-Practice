#include <bits/stdc++.h>
using namespace std;

const int N = 10005;

vector<int> adj[N], tree[N], ford[N];
int dep[N], up[N], down[N], dp[N], arp[N];
int tin[N], tout[N], timer = 0;

void dfs(int i, int p) {
  tin[i] = ++timer;
  for (auto &j : adj[i]) {
    if (!dep[j]) {
      dep[j] = dep[i] + 1;
      tree[i].push_back(j);
      dfs(j, i);
    }
    else {
      if (dep[j] > dep[i] + 1) {
        down[i]++;
        ford[i].push_back(tin[j]);
      }
      if (dep[j] < dep[i] - 1) up[i]++;
    }
  }
  tout[i] = timer;
}

void find(int i, int p) {
  for (auto &j : tree[i]) {
    find(j, p);
  }
  sort(ford[i].begin(), ford[i].end());
  for (auto &j : tree[i]) {
    dp[i] += dp[j] + up[j];
    int l = lower_bound(ford[i].begin(), ford[i].end(),  tin[j]) - ford[i].begin();
    int r = upper_bound(ford[i].begin(), ford[i].end(), tout[j]) - ford[i].begin();
    if (dp[j] + up[j] - (r - l) == 0 && tree[i].size() >= 1 + (i == p)) arp[i] = 1;
  }
  dp[i] -= down[i];
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  freopen("in" , "r", stdin );
  freopen("out", "w", stdout);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    if (!dep[i]) {
      dep[i] = 1;
      dfs(i, -1);
      find(i, i);
    }
  }
  int arb_cnt = 0;
  for (int i = 1; i <= n; i++) {
    for (auto &j : tree[i]) {
      if (!dp[j] && !up[j]) {
        arb_cnt++;
      }
    }
  }
  int arp_cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (arp[i]) {
      arp_cnt++;
    }
  }
  cout << arp_cnt << ' ' << arb_cnt << '\n';
}