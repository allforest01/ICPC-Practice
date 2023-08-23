#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, m, cntM[N], sumM = 0;

void add(int u, int v) {
  if (v > u) {
    if (!cntM[u]) sumM++;
    cntM[u]++;
  }
}

void rem(int u, int v) {
  if (v > u) {
    cntM[u]--;
    if (!cntM[u]) sumM--;
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    add(u, v);
    add(v, u);
  }
  int q; cin >> q;
  for (int i = 1; i <= q; i++) {
    int t;
    cin >> t;
    if (t == 1) {
      int u, v;
      cin >> u >> v;
      add(u, v);
      add(v, u);
    }
    else if (t == 2) {
      int u, v;
      cin >> u >> v;
      rem(u, v);
      rem(v, u);
    }
    else if (t == 3) {
      cout << n - sumM << '\n';
    }
  }
}
