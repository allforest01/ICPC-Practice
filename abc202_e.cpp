#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

vector<int> adj[N], sto[N];
int num[N], tail[N], timer = 0;
int dep[N];
vector<array<int,2>> qr[N];

void dfs(int i) {
  sto[dep[i]].push_back(i);
  num[i] = ++timer;
  for (auto &j : adj[i]) {
    dep[j] = dep[i] + 1;
    dfs(j);
  }
  tail[i] = timer;
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
  int get(int u, int v) {
    return get(v) - get(u - 1);
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  for (int i = 2; i <= n; i++) {
    int x; cin >> x;
    adj[x].push_back(i);
  }
  int q; cin >> q;
  for (int i = 1; i <= q; i++) {
    int u, d;
    cin >> u >> d;
    qr[d + 1].push_back({u, i - 1});
  }
  dep[1] = 1;
  dfs(1);
  BIT bit(n);
  vector<int> res(q);
  for (int i = 1; i <= n; i++) {
    for (auto &v : sto[i]) {
      bit.update(num[v], 1);
    }
    for (auto &j : qr[i]) {
      res[j[1]] = bit.get(num[j[0]], tail[j[0]]);
    }
    for (auto &v : sto[i]) {
      bit.update(num[v], -1);
    }
  }
  for (auto &i : res) cout << i << '\n';
}
