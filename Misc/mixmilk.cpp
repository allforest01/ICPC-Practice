#include <bits/stdc++.h>
using namespace std;

int c[3], m[3];

void pour(int i, int j) {
  int t = min(m[i], c[j] - m[j]);
  m[i] -= t;
  m[j] += t;
}

int main() {
  freopen("mixmilk.in" , "r", stdin );
  freopen("mixmilk.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  for (int i = 0; i < 3; i++) {
    cin >> c[i] >> m[i];
  }
  for (int i = 0; i < 33; i++) {
    pour(0, 1);
    pour(1, 2);
    pour(2, 0);
  }
  pour(0, 1);
  for (int i = 0; i < 3; i++) {
    cout << m[i] << '\n';
  }
}
