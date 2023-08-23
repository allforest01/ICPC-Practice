#include <bits/stdc++.h>
using namespace std;

void Main() {
  int n, a, b;
  cin >> n >> a >> b;
  string s;
  cin >> s;
  if (b >= 0) {
    cout << (a + b) * n << '\n';
    return;
  }
  else {
    int cnt0 = 0, cnt1 = 0;
    for (int i = 0; i < n; i++) {
      if (i == 0 || s[i - 1] != s[i]) {
        if (s[i] == '0') cnt0++;
        if (s[i] == '1') cnt1++;
      }
    }
    cout << a * n + b * (min(cnt0, cnt1) + 1) << '\n';
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
