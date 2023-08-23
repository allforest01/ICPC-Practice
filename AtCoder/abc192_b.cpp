#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  string s;
  cin >> s;
  for (int i = 0; i < s.size(); i += 2) {
    if (isupper(s[i])) {
      cout << "No" << '\n';
      return 0;
    }
  }
  for (int i = 1; i < s.size(); i += 2) {
    if (islower(s[i])) {
      cout << "No" << '\n';
      return 0;
    }
  }
  cout << "Yes" << '\n';
}
