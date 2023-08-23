#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 5005;

int n, b;
vector<int> adj[N];
int cost[N], disc[N], dp[N][N][5];

// node - num - use discount

void dfs(int i) {
  for (auto &j : adj[i]) {
    dfs(j);
  }
  dp[i][1][0] = cost[i];
  dp[i][1][1] = cost[i] - disc[i];
  for (auto &j : adj[i]) {
    
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> b;
  for (int i = 1; i <= n; i++) {
    cin >> cost[i] >> disc[i];
    if (i >= 2) {
      int p; cin >> p;
      adj[p].push_back(i);
    }
  }
  dfs(1);
}
