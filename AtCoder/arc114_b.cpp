#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
const int MOD = 998244353;

vector<int> adj[N];
int vst[N];

void dfs(int i) {
  vst[i] = 1;
  for (auto &j : adj[i]) {
    if (!vst[j]) dfs(j);
  }
}

int pow2(int n) {
  int ret = 1;
  for (int i = 1; i <= n; i++) {
    (ret *= 2) %= MOD;
  }
  return ret;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    adj[i].push_back(x);
    adj[x].push_back(i);
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (!vst[i]) {
      dfs(i);
      ans++;
    }
  }
  ans = pow2(ans);
  if (ans == 0) ans = MOD - 1;
  else ans--;
  cout << ans << '\n';
}
