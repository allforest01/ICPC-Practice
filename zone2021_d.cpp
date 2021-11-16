#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  string s;
  cin >> s;
  bool r = 0;
  deque<char> t;
  for (auto &i : s) {
    if (i == 'R') r = 1 - r;
    else {
      if (!r) t.push_back(i);
      else t.push_front(i);
    }
  }
  list<char> l;
  l.push_back('!');
  if (r) reverse(t.begin(), t.end());
  for (auto &i : t) {
    l.push_back(i);
  }
  for (auto it = next(l.begin()); next(it) != l.end();) {
    if (*it == *next(it)) {
      auto rm0 = it, rm1 = next(it);
      it = prev(it);
      l.erase(rm0);
      l.erase(rm1);
    }
    else ++it;
  };
  for (auto &i : l) {
    if (i != '!') cout << i;
  }
  cout << '\n';
}
