#include <bits/stdc++.h>
using namespace std;

void Main() {
  int n; cin >> n;
  int t = n / 3;
  if (n % 3 == 0) {
    cout << t << ' ' << t << '\n';
  }
  else if (n % 3 == 1) {
    cout << t + 1 << ' ' << t << '\n';
  }
  else if (n % 3 == 2) {
    cout << t << ' ' << t + 1 << '\n';
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
