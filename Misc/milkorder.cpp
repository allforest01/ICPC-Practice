#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  freopen("milkorder.in" , "r", stdin );
  freopen("milkorder.out", "w", stdout);
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> vec(m + 1);
  bool one = 0;
  for (int i = 1; i <= m; i++) {
    cin >> vec[i];
    if (vec[i] == 1) one = 1;
  }
  vector<int> res(n + 1);
  for (int i = 1; i <= k; i++) {
    int c, p;
    cin >> c >> p;
    res[p] = c;
  }
  int last_i = 1, last_j = 1;
  for (int i = 1; i <= n; i++) {
    if (res[i]) {
      for (int j = 1; j <= m; j++) {
        if (res[i] == vec[j]) {
          int tj = j - 1;
          for (int ti = i - 1; ti >= last_i && tj >= last_j; ti--) {
            if (!res[ti]) {
              res[ti] = vec[tj];
              tj--;
            }
          }
          last_j = j + 1;
          last_i = i + 1;
        }
      }
    }
  }
  if (last_j <= m) {
    if (one) {
      int j = last_j;
      for (int i = last_i; i <= n && j <= m; i++) {
        if (!res[i]) {
          res[i] = vec[j];
          j++;
        }
      }
    }
    else {
      int j = m;
      for (int i = n; i >= 1 && j >= last_j; i--) {
        if (!res[i]) {
          res[i] = vec[j];
          j--;
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (res[i] == 1) {
      cout << i << '\n';
      return 0;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (!res[i]) {
      cout << i << '\n';
      return 0;
    }
  }
}
