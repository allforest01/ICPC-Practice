#include <bits/stdc++.h>
using namespace std;

void Main() {
  int a, b, c;
  cin >> a >> b >> c;
  int ma = max(a, max(b, c));
  cout << ((a > b && a > c) ? a : ma + 1) << ' ';
  cout << ((b > a && b > c) ? b : ma + 1) << ' ';
  cout << ((c > a && c > b) ? c : ma + 1) << ' ';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}