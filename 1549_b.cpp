#include <bits/stdc++.h>
using namespace std;

void Main() {
  int n; cin >> n;
  string s1, s2;
  cin >> s1 >> s2;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (s1[i] == '0' && s2[i] == '1') {
      ans++;
      s2[i] = '0';
    }
  }
  for (int i = 0; i < n; i++) {
    if (s1[i] == '0') continue;
    if (i > 0) {
      if (s2[i - 1] == '1') {
        ans++;
        continue;
      }
    }
    if (i + 1 < n) {
      if (s2[i + 1] == '1') {
        ans++;
        s2[i + 1] = '0';
      }
    }
  }
  cout << ans << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
