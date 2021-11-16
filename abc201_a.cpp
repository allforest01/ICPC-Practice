#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int a[3];
  cin >> a[0] >> a[1] >> a[2];
  sort(a, a + 3);
  if (a[2] - a[1] == a[1] - a[0]) {
    cout << "Yes" << '\n';
  }
  else {
    cout << "No" << '\n';
  }
}
