#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<array<int,2>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i][0];
    a[i][1] = i + 1;
  }
  sort(a.begin(), a.end(), greater<array<int,2>>());
  cout << a[1][1] << '\n';
}
