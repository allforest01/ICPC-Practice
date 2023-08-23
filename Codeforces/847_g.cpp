#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<int> cnt(7);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < 7; j++) {
      if (s[j] == '1') cnt[j]++;
    }
  }
  int ans = 0;
  for (int i = 0; i < 7; i++) {
    ans = max(ans, cnt[i]);
  }
  cout << ans << '\n';
}
