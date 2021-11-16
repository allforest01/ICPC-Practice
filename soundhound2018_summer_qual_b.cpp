#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  string s;
  cin >> s;
  int w; cin >> w;
  for (int i = 0; i < s.size(); i += w) {
    cout << s[i];
  }
  cout << '\n';
}
