#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  for (int i = 0; i < (1 << n); i++) {
    int t = i ^ (i >> 1);
    for (int j = n - 1; j >= 0; j--) {
      cout << ((t >> j) & 1);
    }
    cout << '\n';
  }
}
