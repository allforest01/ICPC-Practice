#include <bits/stdc++.h>
using namespace std;

void Main() {
  int n; char c; string s;
  cin >> n >> c >> s;
  s = '#' + s;
  bool flag = 0;
  vector<int> tick(n + 1);
  for (int i = 1; i <= n; i++) {
    if (s[i] != c) {
      flag = 1;
      for (int j = 1; j * j <= i; j++) {
        if (i % j == 0) tick[j] = tick[i / j] = 1;
      }
    }
  }
  if (!flag) {
    cout << 0 << '\n';
    return;
  }
  for (int i = 1; i <= n; i++) {
    if (!tick[i]) {
      cout << 1 << '\n';
      cout << i << '\n';
      return;
    }
  }
  cout << 2 << '\n';
  cout << n - 1 << ' ' << n << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}