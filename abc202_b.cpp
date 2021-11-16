#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  string s;
  cin >> s;
  for (auto &i : s) {
    if (i == '6') i = '9';
    else if (i == '9') i = '6';
  }
  reverse(s.begin(), s.end());
  cout << s << '\n';
}
