#include <bits/stdc++.h>
using namespace std;

#define Bit(x, k) (((x) >> (k)) & 1)
#define Xor(x, k) ((x) ^ (1) << (k))

int main() {
  // cin.tie(0)->sync_with_stdio(0);
  int n, ans = 0;
  cout << "MAX: "; cin >> n;
  for (int j = 0; j < 32; j++) {
    bool flag = 0;
    for (int i = 0; i <= n; i++) {
      if (Bit(i, j)) {
        cout << i << ' ';
        flag = 1;
      }
    }
    if (flag) {
      cout << '\n';
      string s;
      cin >> s;
      if (s == "yes") ans = Xor(ans, j);
    }
  }
  cout << "RESULT: " << ans << '\n';
}
