#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<string> s(n);
  for (auto &i : s) {
    cin >> i;
  }
  vector<int> p(m);
  for (auto &i : p) {
    cin >> i;
  }
  int res = 0;
  for (int j = 0; j < m; j++) {
    map<char,int> cnt;
    for (int i = 0; i < n; i++) {
      cnt[s[i][j]]++;
    }
    int ans = 0;
    for (auto &i : cnt) {
      ans = max(ans, i.second);
    }
    res += ans * p[j];
  }
  cout << res << '\n';
}
