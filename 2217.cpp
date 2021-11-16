#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, q, ans = 0;
int a[N], pos[N];

void to_right(int u, int v) {
  if (pos[a[u]] < pos[a[u] + 1] && pos[a[v]] >= pos[a[u] + 1]) ans++;
  if (pos[a[u]] < pos[a[u] - 1] && pos[a[v]] >= pos[a[u] - 1]) ans--;
}

void to_left(int u, int v) {
  if (pos[a[u]] > pos[a[u] - 1] && pos[a[v]] <  pos[a[u] - 1]) ans++;
  if (pos[a[u]] > pos[a[u] + 1] && pos[a[v]] <  pos[a[u] + 1]) ans--;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pos[a[i]] = i;
    if (!pos[a[i] - 1]) ans++;
  }
  // cout << ans << '\n';
  while (q--) {
    int u, v;
    cin >> u >> v;
    if (u > v) swap(u, v);
    to_right(u, v);
    to_left(v, u);
    swap(pos[a[u]], pos[a[v]]);
    swap(a[u], a[v]);
    cout << ans << '\n';
  }
}
