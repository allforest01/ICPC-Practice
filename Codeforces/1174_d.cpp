#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, x;
  cin >> n >> x;
  vector<int> res;
  int sum = 0;
  set<int> s;
  s.insert(0);
  s.insert(x);
  for (int i = 1; i < (1 << n); i++) {
    if (s.count(i)) continue;
    res.push_back(sum ^ i);
    sum = i;
    s.insert(i);
    s.insert(i ^ x);
  }
  cout << res.size() << '\n';
  for (auto &i : res) cout << i << ' ';
  cout << '\n';
}
