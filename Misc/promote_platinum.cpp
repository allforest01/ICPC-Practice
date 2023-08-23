#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

vector<int> adj[N];
int num[N], tail[N], timer = 0;

void dfs(int i, int p) {
  num[i] = ++timer;
  for (auto &j : adj[i]) {
    if (j != p) dfs(j, i);
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
  freopen("promote.in" , "r", stdin );
  freopen("promote.out", "w", stdout);
  int n; cin >> n;
  vector<array<int,2>> rt(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> rt[i][0];
    rt[i][1] = i;
  }
  for (int i = 2; i <= n; i++) {
    int x; cin >> x;
    adj[i].push_back(x);
    adj[x].push_back(i);
  }
  dfs(1, -1);
  sort(rt.begin() + 1, rt.end(), greater<array<int,2>>());
  vector<int> res(n + 1);
  BIT bit(n);
  for (int i = 1; i <= n; i++) {
    int v = rt[i][1];
    res[v] = bit.get(num[v], tail[v]);
    bit.update(num[v], 1);
  }
  for (int i = 1; i <= n; i++) {
    cout << res[i] << '\n';
  }
}
