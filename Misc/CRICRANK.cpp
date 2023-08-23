#include <bits/stdc++.h>
using namespace std;

void Main() {
  vector<int> a(3), b(3);
  for (auto &i : a) cin >> i;
  for (auto &i : b) cin >> i;
  int cnt_a = 0, cnt_b = 0;
  for (int i = 0; i < 3; i++) {
    if (a[i] > b[i]) cnt_a++;
    if (b[i] > a[i]) cnt_b++;
  }
  if (cnt_a > cnt_b) cout << 'A' << '\n';
  else cout << 'B' << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
