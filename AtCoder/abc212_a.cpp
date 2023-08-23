#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int a, b;
  cin >> a >> b;
  if (0 < a && b == 0) cout << "Gold" << '\n';
  else if (a == 0 && 0 < b) cout << "Silver" << '\n';
  else if (0 < a && 0 < b) cout << "Alloy" << '\n';
}
