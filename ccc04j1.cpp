#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  for (int i = n; i >= 1; i--) {
    if (i * i <= n) {
      cout << "The largest square has side length " << i << ".\n";
      return 0;
    }
  }
}
