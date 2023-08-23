#include <bits/stdc++.h>
using namespace std;

#define taskname ""

typedef long long ll;

void ioset() {
  cin.tie(0)->sync_with_stdio(0);
  if (fopen(taskname".in", "r")) {
    freopen(taskname".in", "r", stdin);
    // freopen(taskname".out", "w", stdout);
  }
}

ll query(int i, int j) {
  cout << "? " << i << ' ' << j << endl;
  ll ret; cin >> ret; return ret;
}

void solve() {
  int n; cin >> n;
  vector<ll> h(n + 1), t(n + 1), r(n + 1);
  for (int i = 2; i <= n; i++) {
    h[i] = query(1, i);
  }
  r[n] = query(1, n) / 2;
  t[n - 1] = h[n] + r[n];
  for (int i = n - 1; i >= 2; i--) {
    r[i] = (t[i] - h[i]) / 2;
    t[i - 1] = h[i] + r[i];
  }
  r[1] = t[1];
  cout << "! ";
  for (int i = 1; i <= n; i++) {
    cout << r[i] << " \n"[i == n];
  }
  cout << flush;
}

int main() {
  // ioset();
  solve();
}
