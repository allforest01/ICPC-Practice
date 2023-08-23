#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; string s;
  cin >> n >> s;
  int r = 0, b = 0;
  for (auto &i : s) {
    if (i == 'R') r++;
    if (i == 'B') b++;
  }
  cout << (r > b ? "Yes" : "No") << '\n';
}
