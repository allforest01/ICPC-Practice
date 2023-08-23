#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int a, b, c;
  while (cin >> a >> b >> c) {
    if (a == b + c || b == a + c || c == a + b) {
      cout << "yes" << '\n';
    }
    else {
      cout << "no" << '\n';
    }
  }
}
