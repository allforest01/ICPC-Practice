#include <bits/stdc++.h>
using namespace std;

void Main() {
  int n; cin >> n;
  int odd = 0, even = 0;
  for (int i = 0; i < n * 2; i++) {
    int x; cin >> x;
    if (x % 2) odd++; else even++;
  }
  if (odd == even) cout << "Yes" << '\n';
  else cout << "No" << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
