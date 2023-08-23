#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int a, b;
  cin >> a >> b;
  if (a <= b && b <= a * 6) {
    cout << "Yes" << '\n';
  }
  else {
    cout << "No" << '\n';
  }
}
