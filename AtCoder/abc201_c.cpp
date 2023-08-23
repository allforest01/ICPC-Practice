#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  string s;
  cin >> s;
  int ans = 0;
  for (int a = 0; a <= 9; a++)
  for (int b = 0; b <= 9; b++)
  for (int c = 0; c <= 9; c++)
  for (int d = 0; d <= 9; d++) {
    vector<int> v(10);
    v[a] = v[b] = v[c] = v[d] = 1;
    bool flag = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == 'o' && v[i] == 0) {
        flag = 1;
        break;
      }
      if (s[i] == 'x' && v[i] == 1) {
        flag = 1;
        break;
      }
    }
    if (!flag) ans++;
  }
  cout << ans << '\n';
}
