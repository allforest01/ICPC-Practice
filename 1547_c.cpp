#include <bits/stdc++.h>
using namespace std;

void Main() {
  int k, n, m;
  cin >> k >> n >> m;
  vector<int> a(n), b(m);
  for (auto &i : a) cin >> i;
  for (auto &i : b) cin >> i;
  int i = 0, j = 0;
  vector<int> res;
  while (i < n || j < m) {
    if (i < n && a[i] == 0) {
      res.push_back(a[i]);
      k++;
      i++;
    }
    else if (j < m && b[j] == 0) {
      res.push_back(b[j]);
      k++;
      j++;
    }
    else if (i < n && a[i] <= k) {
      res.push_back(a[i]);
      i++;
    }
    else if (j < m && b[j] <= k) {
      res.push_back(b[j]);
      j++;
    }
    else {
      cout << -1 << '\n';
      return;
    }
  }
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
