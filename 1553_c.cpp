#include <bits/stdc++.h>
using namespace std;

int rm_odd(int p) {
  return (10 - p) / 2;
}

int rm_even(int p) {
  return (10 - p + 1) / 2;
}

void Main() {
  string s;
  cin >> s;
  int ans = 10;
  s = '$' + s;
  int cnt_odd = 0, cnt_even = 0;
  for (int i = 1; i <= 10; i++) {
    if (i % 2) {
      if (s[i] == '1' || s[i] == '?') cnt_odd++;
    }
    else {
      if (s[i] == '1') cnt_even++;
    }
    if (cnt_odd > cnt_even + rm_even(i)) {
      ans = min(ans, i);
      break;
    }
  }
  cnt_odd = 0; cnt_even = 0;
  for (int i = 1; i <= 10; i++) {
    if (i % 2) {
      if (s[i] == '1') cnt_odd++;
    }
    else {
      if (s[i] == '1' || s[i] == '?') cnt_even++;
    }
    if (cnt_even > cnt_odd + rm_odd(i)) {
      ans = min(ans, i);
      break;
    }
  }
  cout << ans << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
