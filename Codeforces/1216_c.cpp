#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  vector<int> x(6), y(6);
  for (int i = 0; i < 6; i++) {
    cin >> x[i] >> y[i];
  }
  for (int i = 0; i <= 1; i++)
  for (double j = y[0]; j <= y[1]; j += 0.5) {
    if (x[2] <= x[i] && x[i] <= x[3] && y[2] <= j && j <= y[3]) {
      continue;
    }
    if (x[4] <= x[i] && x[i] <= x[5] && y[4] <= j && j <= y[5]) {
      continue;
    }
    cout << "YES" << '\n';
    return 0;
  }
  for (int i = 0; i <= 1; i++)
  for (double j = x[0]; j <= x[1]; j += 0.5) {
    if (x[2] <= j && j <= x[3] && y[2] <= y[i] && y[i] <= y[3]) {
      continue;
    }
    if (x[4] <= j && j <= x[5] && y[4] <= y[i] && y[i] <= y[5]) {
      continue;
    }
    cout << "YES" << '\n';
    return 0;
  }
  cout << "NO" << '\n';
}
