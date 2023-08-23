#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--)
  {
    long long n; cin >> n;
    int cnt = 0;
    while (n % 2 == 0) {
      cnt++;
      n /= 2;
    }
    if (cnt == 0) cout << "Odd" << '\n';
    else if (cnt == 1) cout << "Same" << '\n';
    else cout << "Even" << '\n';
  }
}
