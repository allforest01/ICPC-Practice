#include <bits/stdc++.h>
using namespace std;

void Main() {
  int n; cin >> n;
  int sum = 0, i = 1, j = 0;
  while (sum < n) {
    sum += i;
    i += 2;
    j++;
  }
  cout << j << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
