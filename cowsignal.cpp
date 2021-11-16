#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("cowsignal.in" , "r", stdin );
  freopen("cowsignal.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  int n, m, k;
  cin >> n >> m >> k;
  vector<string> a(n);
  for (auto &i : a) cin >> i;
  for (int i = 0; i < n * k; i++) {
    for (int j = 0; j < m * k; j++) {
      cout << a[i / k][j / k];
    }
    cout << '\n';
  }
}
