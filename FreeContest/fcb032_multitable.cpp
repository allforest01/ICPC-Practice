#include <bits/stdc++.h>
using namespace std;

const int N = 55;

int a[N][N];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  for (int i = 1; i <= n; i++)
  for (int j = 1; j <= n; j++) {
    cin >> a[i][j];
  }
  for (int i = 1; i <= n; i++) {
    cout << sqrt(a[i][i]) << ' ';
  }
  cout << '\n';
}
