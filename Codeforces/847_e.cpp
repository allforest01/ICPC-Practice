#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; string s;
  cin >> n >> s;
  s = '$' + s;
  vector<int> ast, pac;
  for (int i = 1; i <= n; i++) {
    if (s[i] == '*') ast.push_back(i);
    if (s[i] == 'P') pac.push_back(i);
  }
  auto check = [&](int x) {
    int p = 0;
    for (int i = 0; i < (int) pac.size(); i++) {
      if (abs(pac[i] - ast[p]) > x) continue;
      int j = p + 1;
      while (j < (int) ast.size()) {
        int d = min(abs(pac[i] - ast[p]), abs(pac[i] - ast[j])) + abs(ast[p] - ast[j]);
        if (d > x) break;
        j++;
      }
      j--;
      p = j + 1;
      if (p == (int) ast.size()) break;
    }
    return (p == (int) ast.size());
  };
  int l = 0, r = 2 * n, ans = -1;
  while (l <= r) {
    int x = (l + r) / 2;
    if (check(x)) {
      ans = x;
      r = x - 1;
    }
    else l = x + 1;
  }
  cout << ans << '\n';
}
