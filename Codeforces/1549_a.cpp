#include <bits/stdc++.h>
using namespace std;

void Main() {
  int p; cin >> p;
  if (p == 5) {
    cout << "2 4\n";
    return;
  }
  cout << 2 << ' ' << p / 2 << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
