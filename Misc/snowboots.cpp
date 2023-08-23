#include <bits/stdc++.h>
using namespace std;

struct Dsu {
  vector<int> root, hang;
  Dsu(int n): root(n + 1), hang(n + 1) {
    for (int i = 1; i <= n; i++) {
      root[i] = i;
      hang[i] = 1;
    }
  }
  int find(int i) {
    if (i == root[i]) return i;
    return root[i] = find(root[i]);
  }
  bool unite(int u, int v) {
    u = find(u); v = find(v);
    if (u == v) return false;
    if (hang[u] < hang[v]) swap(u, v);
    hang[u] += hang[v];
    root[v] = u;
    return true;
  }
  int num(int i) {
    return hang[find(i)];
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  freopen("snowboots.in" , "r", stdin );
  freopen("snowboots.out", "w", stdout);
  int n, q;
  cin >> n >> q;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  set<array<int,2>> st;
  for (int i = 1; i <= n; i++) {
    st.insert({a[i], i});
  }
  vector<array<int,3>> qr(q);
  for (int i = 0; i < q; i++) {
    cin >> qr[i][0] >> qr[i][1];
    qr[i][2] = i;
  }
  sort(qr.begin(), qr.end(), greater<array<int,3>>());
  vector<int> res(q);
  Dsu dsu(n);
  int ma = 1;
  for (auto &qi : qr) {
    int s = qi[0], d = qi[1], p = qi[2];
    auto it = st.upper_bound({s, INT_MAX});
    while (it != st.end())
    {
      int t = (*it)[1];
      dsu.unite(t, t + 1);
      ma = max(ma, dsu.num(t));
      st.erase(it);
      it = st.upper_bound({s, INT_MAX});
    }
    if (d >= ma) res[p] = 1;
  }
  for (auto &i : res) cout << i << '\n';
}
