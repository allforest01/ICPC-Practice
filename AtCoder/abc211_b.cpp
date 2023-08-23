#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  set<string> d = {"H", "2B", "3B", "HR"};
  string s;
  while (cin >> s) {
    d.erase(s);
  }
  cout << (!d.size() ? "Yes" : "No") << '\n';
}
