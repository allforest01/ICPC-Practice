#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  long long n; cin >> n;
  string res;
  while (n != 0) {
    if (n % 2) {
      res += 'A';
      n--;
    }
    else {
      res += 'B';
      n /= 2;
    }
  }
  reverse(res.begin(), res.end());
  cout << res << '\n';
}
