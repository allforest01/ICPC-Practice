#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 100005;

vector<int> adj[N];
int col[N], res[N];
int sum[N], siz[N];
map<int,int> cnt[N];

void dfs(int i, int p) {
  cnt[i][col[i]] = 1;
  sum[i] = col[i];
  siz[i] = 1;
  for (auto &j : adj[i]) {
    if (j != p) {
      dfs(j, i);
      if (cnt[i].size() < cnt[j].size()) {
        swap(cnt[i], cnt[j]);
        swap(sum[i], sum[j]);
        swap(siz[i], siz[j]);
      }
      for (auto &k : cnt[j]) {
        int t = cnt[i][k.first];
        cnt[i][k.first] += k.second;
        if (cnt[i][k.first] > siz[i]) {
          siz[i] = cnt[i][k.first];
          sum[i] = k.first;
        }
        else if (cnt[i][k.first] == siz[i]) {
          sum[i] += k.first;
        }
      }
    }
  }
  res[i] = sum[i];
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> col[i];
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1, -1);
  for (int i = 1; i <= n; i++) {
    cout << res[i] << ' ';
  }
  cout << '\n';
}
