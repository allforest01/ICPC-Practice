#include <bits/stdc++.h>
using namespace std;

const int N = 105;

vector<int> adj[N];
int color[N];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  freopen("revegetate.in" , "r", stdin );
  freopen("revegetate.out", "w", stdout);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    set<int> s;
    for (auto &j : adj[i]) {
      s.insert(color[j]);
    }
    for (int c = 1; c <= 4; c++) {
      if (!s.count(c)) {
        color[i] = c;
        break;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << color[i];
  }
  cout << '\n';
}
