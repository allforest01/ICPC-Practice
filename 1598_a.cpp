#include <bits/stdc++.h>
using namespace std;

void Main() {
  int n; cin >> n;
  string s1, s2;
  cin >> s1 >> s2;
  for (int i = 0; i < n; i++) {
    if (s1[i] == '1' && s2[i] == '1') {
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