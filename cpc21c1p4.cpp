#include <bits/stdc++.h>
using namespace std;

struct Sub1 {
  int n, m;
  vector<int> vst;
  vector<vector<int>> adj;

  Sub1(int n, int m): n(n), m(m), vst(n + 1), adj(n + 1) {}

  int dfs(int i) {
    vst[i] = 1;
    int ret = i;
    for (auto &j : adj[i]) {
      if (!vst[j]) {
        ret = max(ret, dfs(j));
      }
    }
    return ret;
  }

  void Main() {
    for (int i = 1; i <= m; i++) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
    }
    int ans1 = -1, ans2 = -1;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        vst[j] = 0;
      }
      int t = dfs(i);
      if ((t > i) && (i > ans1) || (i == ans1 && t > ans2)) {
        ans1 = i;
        ans2 = t;
      }
    }
    if (ans1 == -1) cout << -1 << '\n';
    else cout << ans1 << ' ' << ans2 << '\n';
  }
};

struct Sub2 {
  int n, m;
  vector<int> vst, sav;
  vector<vector<int>> adj;

  Sub2(int n, int m): n(n), m(m), vst(n + 1), adj(n + 1) {}

  void dfs(int i) {
    vst[i] = 1;
    sav.push_back(i);
    for (auto &j : adj[i]) {
      if (!vst[j]) dfs(j);
    }
  }

  void Main() {
    for (int i = 1; i <= m; i++) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    int ans1 = -1, ans2 = -1;
    for (int i = 1; i <= n; i++) {
      if (!vst[i]) {
        dfs(i);
        sort(sav.begin(), sav.end(), greater<int>());
        if (sav.size() >= 2) {
          if (sav[1] > ans1 || (sav[1] == ans1 && sav[0] > ans2)) {
            ans1 = sav[1];
            ans2 = sav[0];
          }
        }
        sav.clear();
      }
    }
    if (ans1 == -1) cout << -1 << '\n';
    else cout << ans1 << ' ' << ans2 << '\n';
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  if (n <= 5000 && m <= 10000) {
    Sub1 sol(n, m);
    sol.Main();
  }
  else {
    Sub2 sol(n, m);
    sol.Main();
  }
}
