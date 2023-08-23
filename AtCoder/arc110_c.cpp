#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<int> a(n + 1), b(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    b[a[i]] = i;
  }
  set<int> s;
  vector<int> res;
  for (int i = 1; i <= n; i++) {
    while (b[i] != i) {
      if (b[i] < i) {
        if (s.count(b[i])) {
          cout << -1 << '\n';
          return 0;
        }
        s.insert(b[i]);
        res.push_back(b[i]);
        int j = a[b[i] + 1];
        int t1 = b[i];
        int t2 = b[j];
        int t3 = a[b[i]];
        int t4 = a[b[j]];
        b[i] = t2;
        b[j] = t1;
        a[t1] = t4;
        a[t2] = t3;
      }
      else if (b[i] > i) {
        if (s.count(b[i] - 1)) {
          cout << -1 << '\n';
          return 0;
        }
        s.insert(b[i] - 1);
        res.push_back(b[i] - 1);
        int j = a[b[i] - 1];
        int t1 = b[i];
        int t2 = b[j];
        int t3 = a[b[i]];
        int t4 = a[b[j]];
        b[i] = t2;
        b[j] = t1;
        a[t1] = t4;
        a[t2] = t3;
      }
    }
  }
  if (res.size() != n - 1) {
    cout << -1 << '\n';
    return 0;
  }
  for (auto &i : res) {
    cout << i << '\n';
  }
}
