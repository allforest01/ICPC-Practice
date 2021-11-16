#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("shuffle.in" , "r", stdin );
  freopen("shuffle.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<int> a(n);
  vector<string> b(n), c(n);
  for (auto &i : a) {
    cin >> i;
    i--;
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  for (int j = 0; j < 3; j++) {
    for (int i = 0; i < n; i++) {
      c[i] = b[a[i]];
    }
    for (int i = 0; i < n; i++) {
      b[i] = c[i];
    }
  }
  for (auto &i : b) cout << i << '\n';
}
