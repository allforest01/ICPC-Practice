#include <bits/stdc++.h>
using namespace std;

void Main() {
  int n; cin >> n;
  string s;
  cin >> s;
  string t = s;
  sort(t.begin(), t.end());
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (t[i] != s[i]) ans++;
  }
  cout << ans << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
