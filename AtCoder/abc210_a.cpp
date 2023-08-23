#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, a, x, y;
  cin >> n >> a >> x >> y;
  if (n > a) {
    cout << a * x + (n - a) * y << '\n';
  }
  else {
    cout << n * x << '\n';
  }
}
