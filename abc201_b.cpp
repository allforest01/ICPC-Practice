#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<pair<int,string>> v(n);
  for (auto &i : v) {
    cin >> i.second >> i.first;
  }
  sort(v.begin(), v.end());
  cout << v[v.size() - 2].second << '\n';
}
