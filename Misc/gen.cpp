#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("in", "w", stdout);
  srand(time(NULL));
  int n = 10, k = 3;
  cout << n << ' ' << k << '\n';
  for (int i = 0; i < n; i++) {
    cout << rand() % 21 + 1 << ' ';
  }
  cout << '\n';
}
