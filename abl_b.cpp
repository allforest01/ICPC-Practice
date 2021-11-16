#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  long long a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << (min(b, d) - max(a, c) >= 0 ? "Yes" : "No") << '\n';
}
