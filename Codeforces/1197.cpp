#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
bool chmin(ll &a, ll b) {
  return a > b ? (a = b, 1) : 0;
}
 
int main() {
  int n, m;
  cin >> n >> m;
  vector<array<int,3>> edges(m);
  for (auto &e : edges) {
    cin >> e[1] >> e[2] >> e[0];
  }
  vector<ll> dist(n + 1, 0);
  vector<int> trace(n + 1);
  int last = -1;
  for (int i = 1; i <= n; i++) {
    last = -1;
    for (auto &e : edges) {
      int u = e[1], v = e[2], w = e[0];
      if (chmin(dist[v], dist[u] + w)) {
        trace[v] = u;
        last = v;
      }
    }
  }
  if (last == -1) {
    cout << "NO" << '\n';
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    last = trace[last];
  }
  vector<int> res;
  int t = last;
  do {
    res.push_back(t);
    t = trace[t];
  } while (t != last);
  reverse(res.begin(), res.end());
  cout << "YES" << '\n';
  for (auto &i : res) {
    cout << i << ' ';
  }
  cout << res[0] << '\n';
}