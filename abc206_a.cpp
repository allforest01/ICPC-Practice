#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  double n; cin >> n;
  n = floor(n * 1.08);
  if (n < 206) cout << "Yay!" << '\n';
  else if (n == 206) cout << "so-so" << '\n';
  else cout << ":(" << '\n';
}
