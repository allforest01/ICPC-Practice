#include <bits/stdc++.h>
using namespace std;

void Main() {
  int n; cin >> n;
  string s;
  cin >> s;
  for (int i = 0; i <= 4; i++) {
    if (s.substr(0, i) + s.substr(n - (4 - i), 4 - i) == "2020") {
      cout << "YES" << '\n';
      return;
    }
  }
  cout << "NO" << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
