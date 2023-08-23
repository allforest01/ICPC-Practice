#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)((x).size())

void Main() {
  string s;
  cin >> s;
  deque<char> d(s.begin(), s.end());
  while (sz(d)) {
    char c = sz(d) + 'a' - 1;
    if (d.front() == c) d.pop_front();
    else if (d.back() == c) d.pop_back();
    else {
      cout << "NO" << '\n';
      return;
    }
  }
  cout << "YES" << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
