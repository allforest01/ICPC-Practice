#include <bits/stdc++.h>
using namespace std;

long long sum(long long n) {
  return n * (n + 1) / 2;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  long long n; cin >> n;
  long long p = sqrt(n * 2);
  while (sum(p + 1) <= n + 1) p++;
  while (n + 1 - sum(p) <= p) p--;
  cout << n - p << '\n';
}
