#include <bits/stdc++.h>
using namespace std;

void Main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n + 1), vst(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (!vst[i]) {
      int c = 0, t = i;
      while (!vst[t]) {
        c++;
        vst[t] = 1;
        t = a[t];
      }
      cnt += c - 1;
    }
  }
  vector<int> res;
  // no shift
  if (cnt <= m) {
    res.push_back(0);
  }
  // if shift
  if (cnt && m) {
    for (int i = max((n - 1) - (m + 1 - cnt), 1); i <= n - 1; i++) {
      res.push_back(i);
    }
  }
  cout << res.size() << ' ';
  for (auto &i : res) {
    cout << i << ' ';
  }
  cout << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
