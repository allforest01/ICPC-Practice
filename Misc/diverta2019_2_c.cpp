#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  multiset<int> s;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    s.insert(x);
  }
  int sum = *s.begin();
  s.erase(s.begin());
  vector<pair<int,int>> res;
  while (s.size() > 1 && *s.begin() >= 0) {
    res.emplace_back(sum, *s.begin());
    sum -= *s.begin();
    s.erase(s.begin());
  }
  int pe = *prev(s.end());
  res.emplace_back(pe, sum);
  pe -= sum;
  s.erase(prev(s.end()));
  for (auto &i : s) {
    res.emplace_back(pe, i);
    pe -= i;
  }
  cout << pe << '\n';
  for (auto &i : res) {
    cout << i.first << ' ' << i.second << '\n';
  }
}
