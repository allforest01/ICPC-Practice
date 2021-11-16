#include <bits/stdc++.h>
using namespace std;

void Main() {
  int n; cin >> n;
  deque<int> a(n);
  for (auto &i : a) cin >> i;
  vector<int> res;
  bool left = true;
  while (a.size()) {
    if (left) {
      res.push_back(a.front());
      a.pop_front();
    }
    else {
      res.push_back(a.back());
      a.pop_back();
    }
    left ^= 1;
  }
  for (auto &i : res) cout << i << ' ';
  cout << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
