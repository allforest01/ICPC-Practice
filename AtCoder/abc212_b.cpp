#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  array<int,4> a;
  for (int i = 0; i < 4; i++) {
    char c; cin >> c;
    a[i] = c - '0';
  }
  if (a[0] == a[1] && a[1] == a[2] && a[2] == a[3]) {
    cout << "Weak" << '\n';
    return 0;
  }
  for (int i = 0; i < 3; i++) {
    if (a[(i + 1) % 4] != (a[i] + 1) % 10) {
      cout << "Strong" << '\n';
      return 0;
    }
  }
  cout << "Weak" << '\n';
}
