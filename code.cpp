#include <bits/stdc++.h>
using namespace std;

int f(int n, int c) {
  if (n < c) return n;
  int doi = n / c;
  int du  = n % c;
  return (n - du) + f(doi + du, c);
}

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  cout << f(a + b, c) - (a + b) << '\n';
}
