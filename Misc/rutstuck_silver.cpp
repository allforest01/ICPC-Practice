#include <bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>> &adj, vector<int> &res, int i) {
  for (auto &j : adj[i]) {
    res[i] += dfs(adj, res, j) + 1;
  }
  return res[i];
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<array<int,3>> N, E;
  for (int i = 0; i < n; i++) {
    char dir; int x, y;
    cin >> dir >> x >> y;
    if (dir == 'N') N.push_back({x, y, i});
    if (dir == 'E') E.push_back({y, x, i});
  }
  int nN = N.size(), nE = E.size();
  sort(N.begin(), N.end());
  sort(E.begin(), E.end());
  vector<int> stopped(n), deg(n);
  vector<vector<int>> adj(n);
  for (int i = 0; i < nN; i++)
  for (int j = 0; j < nE; j++) {
    int i_x = N[i][0], i_y = N[i][1], i_id = N[i][2];
    int j_x = E[j][1], j_y = E[j][0], j_id = E[j][2];
    if (i_y < j_y && i_x > j_x) {
      int dx = i_x - j_x;
      int dy = j_y - i_y;
      if (stopped[i_id] && stopped[i_id] < dy) continue;
      if (stopped[j_id] && stopped[j_id] < dx) continue;
      if (dy > dx) {
        if (stopped[i_id]) continue;
        stopped[i_id] = dy;
        adj[j_id].push_back(i_id);
        deg[i_id]++;
      }
      else if (dy < dx) {
        if (stopped[j_id]) continue;
        stopped[j_id] = dx;
        adj[i_id].push_back(j_id);
        deg[j_id]++;
      }
    }
  }
  vector<int> res(n);
  for (int i = 0; i < n; i++) {
    if (!deg[i]) dfs(adj, res, i);
  }
  for (auto &i : res) cout << i << '\n';
}
