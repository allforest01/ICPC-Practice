#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<int> a(n * 2);
  int sum = 0;
  for (int i = 0; i < n * 2; i++) {
    int x, y;
    cin >> x >> y;
    sum += x;
    a[i] = y - x;
  }
  sort(a.begin(), a.end());
  for (int i = 0; i < n; i++) {
    sum += a[i];
  }
  cout << sum << '\n';
}
