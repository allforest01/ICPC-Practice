#include <bits/stdc++.h>
using namespace std;

#define sqr(x) ((x)*(x))

const int N = 205;
const double EPS = 1e-10;

vector<int> adj[N];
int vst[N];

bool can_trans(int x1, int y1, int x2, int y2, int p) {
  double dist = sqrt(sqr(x1 - x2) + sqr(y1 - y2));
  if (dist <= (double) p + EPS) return true;
  return false;
}

void dfs(int i) {
  vst[i] = 1;
  for (auto &j : adj[i]) {
    if (!vst[j]) dfs(j);
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  freopen("moocast.in" , "r", stdin );
  freopen("moocast.out", "w", stdout);
  int n; cin >> n;
  vector<vector<int>> v(n);
  for (auto &i : v) {
    int x, y, p;
    cin >> x >> y >> p;
    i = vector<int>({x, y, p});
  }
  for (int i = 0; i < n; i++)
  for (int j = 0; j < n; j++) {
    if (i == j) continue;
    if (can_trans(v[i][0], v[i][1], v[j][0], v[j][1], v[i][2])) {
      adj[i + 1].push_back(j + 1);
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    memset(vst, 0, sizeof(vst));
    dfs(i);
    int cnt = 0;
    for (int j = 1; j <= n; j++) {
      if (vst[j]) cnt++;
    }
    ans = max(ans, cnt);
  }
  cout << ans << '\n';
}
