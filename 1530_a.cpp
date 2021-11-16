#include <bits/stdc++.h>
using namespace std;

void Main() {
  string s;
  cin >> s;
  int ma = 1;
  for (int i = 0; i < s.size(); i++) {
    ma = max(ma, s[i] - '0');
  }
  cout << ma << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
