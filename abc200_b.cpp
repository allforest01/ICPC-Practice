#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  long long n, k;
  cin >> n >> k;
  while (k --> 0) {
    if (n % 200 == 0) n /= 200;
    else n = n * 1000 + 200;
  }
  cout << n << '\n';
}
