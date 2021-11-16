#include <bits/stdc++.h>
using namespace std;

void Main() {
  int n; cin >> n;
  n *= 2;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end(), greater<int>());
  for (int i = 1; i < n; i++) {
    int sum = a[0] + a[i];
    multiset<int> ms;
    for (auto &j : a) {
      ms.insert(j);
    }
    vector<pair<int,int>> res;
    while (ms.size()) {
      auto it_mx = prev(ms.end());
      auto it_rm = ms.find(sum - *it_mx);
      if (it_rm == ms.end() || it_mx == it_rm) break;
      sum = *it_mx;
      res.push_back(make_pair(*it_mx, *it_rm));
      ms.erase(it_mx);
      ms.erase(it_rm);
    }
    if (!ms.size()) {
      cout << "YES" << '\n';
      cout << a[0] + a[i] << '\n';
      for (auto &j : res) {
        cout << j.first << ' ' << j.second << '\n';
      }
      return;
    }
  }
  cout << "NO" << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
