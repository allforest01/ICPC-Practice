#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
  if (n <= 1) return false;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  for (int i = 2; n > 0; i++) {
    if (i % 5 == 1 && isPrime(i)) {
      cout << i << ' ';
      n--;
    }
  }
  cout << '\n';
}
