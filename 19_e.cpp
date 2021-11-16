#include <bits/stdc++.h>
using namespace std;

const int N = 10005;

vector<int> adj[N], pos[N];
int tin[N], low[N], timer = 0;
int col[N], dp1[N], dp2[N], vsted[N];
vector<int> res1, res2, res3;

void chmin(int &a, int b) {
  if (a > b) a = b;
}

void dfs(int i, int p) {
  tin[i] = low[i] = ++timer;
  for (int k = 0; k < (int) adj[i].size(); k++) {
    int j = adj[i][k];
    if (j == p) continue;
    if (!tin[j]) {
      col[j] = col[i] ^ 1;
      dfs(j, i);
      chmin(low[i], low[j]);
      dp1[i] += dp1[j];
      dp2[i] += dp2[j];
    }
    else if (tin[j] < tin[i]) {
      if (col[j] == col[i]) {
        res1.push_back(pos[i][k]);
        dp1[i]++;
      }
      else {
        res3.push_back(pos[i][k]);
        dp2[i]++;
      }
    }
    else if (tin[j] > tin[i]) {
      if (col[j] == col[i]) {
        dp1[i]--;
      }
      else {
        dp2[i]--;
      }
    }
  }
}

void vst(int i, int t) {
  vsted[i] = 1;
  for (int k = 0; k < (int) adj[i].size(); k++) {
    int j = adj[i][k];
    if (!vsted[j]) {
      vst(j, pos[i][k]);
    }
  }
  if ((dp1[i] == res1.size() && !dp2[i]) || (!res1.size())) {
    if (t != -1) res2.push_back(t);
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
    adj[v].push_back(u);
    pos[u].push_back(i);
    pos[v].push_back(i);
  }
  bool flag = 0;
  vector<int> res;
  for (int i = 1; i <= n; i++) {
    if (!tin[i]) {
      dfs(i, -1);
      vst(i, -1);
      if (res1.size() && flag) {
        cout << 0 << '\n';
        return 0;
      }
      if (flag) continue;
      if (res1.size()) {
        res.clear();
        flag = 1;
      }
      if (res1.size() == 1) {
        res.push_back(res1[0]);
      }
      for (auto &i : res2) {
        res.push_back(i);
      }
      if (!res1.size()) {
        for (auto &i : res3) {
          res.push_back(i);
        }
      }
      res1.clear();
      res2.clear();
      res3.clear();
    }
  }
  sort(res.begin(), res.end());
  cout << res.size() << '\n';
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << ' ';
  }
  if (res.size()) cout << '\n';
}
