#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  long long n; cin >> n;
  long long k = 0;
  while ((1ll << (k + 1)) <= n) k++;
  cout << k << '\n';
}
