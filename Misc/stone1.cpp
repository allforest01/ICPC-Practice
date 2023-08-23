#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int N = 405;

vector<int> adj[N];
int stone[N];

void dfs(int i) {
  if (!adj[i].size()) {
    stone[i] = 1;
    return;
  }
  int ma = 0, cnt = 0;
  for (auto &j : adj[i]) {
    dfs(j);
    ma = max(ma, stone[j]);
  }
  for (auto &j : adj[i]) {
    if (ma == stone[j]) cnt++;
  }
  stone[i] = ma + cnt - 1;
}

signed main() {
  // freopen("in" , "r", stdin );
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  for (int t; cin >> t;) {
    int k; cin >> k;
    for (int i = 0; i < k; i++) {
      int x; cin >> x;
      adj[t].push_back(x);
    }
  }
  dfs(1);
  cout << stone[1] << endl;
}
