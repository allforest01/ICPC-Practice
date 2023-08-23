#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  set<char> s;
  for (int i = 0; i < 5; i++) {
    char c; cin >> c;
    s.insert(c);
  }
  for (char c = 'a'; c <= 'z'; c++) {
    if (!s.count(c)) {
      cout << c << '\n';
      return 0;
    }
  }
}
