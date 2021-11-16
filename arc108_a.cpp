#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  long long s, p;
  cin >> s >> p;
  for (long long i = 1; i * i <= p; i++) {
    if (i + p / i == s) {
      cout << "Yes" << '\n';
      return 0;
    }
  }
  cout << "No" << '\n';
}
