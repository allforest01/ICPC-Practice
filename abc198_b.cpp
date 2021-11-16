#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  string s;
  cin >> s;
  while (s.back() == '0') s.erase(s.size() - 1, 1);
  for (int i = 0; i < s.size(); i++) {
    if (s[i] != s[s.size() - i - 1]) {
      cout << "No" << '\n';
      return 0;
    }
  }
  cout << "Yes" << '\n';
}
