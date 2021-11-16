#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  double a, b;
  cin >> a >> b;
  cout << setprecision(10) << fixed << (a - b) / a * 100 << '\n';
}
