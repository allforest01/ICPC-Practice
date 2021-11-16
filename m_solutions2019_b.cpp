#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  string s;
  cin >> s;
  int cnt = 0;
  for (auto &i : s) {
    if (i == 'o') cnt++;
  }
  cout << (cnt + (15 - s.size()) >= 8 ? "YES" : "NO") << '\n';
}
