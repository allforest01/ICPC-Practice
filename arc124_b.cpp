#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<int> a(n), b(n);
  for (auto &i : a) cin >> i;
  for (auto &i : b) cin >> i;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    v.push_back(a[0] ^ a[i]);
  }
  sort(v.begin(), v.end());
  set<int> res;
  for (int p = 0; p < n; p++) {
    vector<int> t;
    for (int i = 0; i < n; i++) {
      t.push_back(b[p] ^ b[i]);
    }
    sort(t.begin(), t.end());
    if (t == v) res.insert(a[0] ^ b[p]);
  }
  cout << res.size() << '\n';
  for (auto &i : res) {
    cout << i << '\n';
  }
}
