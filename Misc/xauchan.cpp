#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  string s; cin >> s;
  map<char,int> mem;
  for (auto &i : s) {
    mem[i]++;
  }
  for (auto &i : mem) {
    if (i.second % 2) {
      cout << "No" << '\n';
      return 0;
    }
  }
  cout << "Yes" << '\n';
}
