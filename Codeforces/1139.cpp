#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

vector<int> adj[N];
vector<array<int,2>> segs[N];
int tin[N], tout[N], timer = 0;
int clr[N], last[N], col[N];

void dfs(int i, int p) {
  tin[i] = ++timer;
  col[timer] = clr[i];
  for (auto &j : adj[i]) {
    if (j != p) dfs(j, i);
  }
  tout[i] = timer;
}

struct BIT {
  int n; vector<int> bit;
  BIT(int n): n(n), bit(n + 1) {}
  void update(int i, int val) {
    for (; i <= n; i += i & -i) {
      bit[i] += val;
    }
  }
  int get(int i) {
    int val = 0;
    for (; i; i -= i & -i) {
      val += bit[i];
    }
    return val;
  }
  void update(int u, int v, int val) {
    update(u, val);
    update(v + 1, -val);
  }
};

void compress(int a[], int l, int r) {
  set<int> s;
  for (int i = l; i <= r; i++) {
    s.insert(a[i]);
  }
  vector<int> v(s.begin(), s.end());
  for (int i = l; i <= r; i++) {
    a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> clr[i];
  }
  compress(clr, 1, n);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1, -1);
  BIT bit(n);
  for (int i = 1; i <= n; i++) {
    segs[tout[i]].push_back({tin[i], i});
  }
  vector<int> res(n + 1);
  for (int i = 1; i <= n; i++) {
    bit.update(i, 1);
    if (last[col[i]]) bit.update(last[col[i]], -1);
    last[col[i]] = i;
    for (auto &j : segs[i]) {
      res[j[1]] = bit.get(i) - bit.get(j[0] - 1);
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << res[i] << ' ';
  }
  cout << '\n';
}
