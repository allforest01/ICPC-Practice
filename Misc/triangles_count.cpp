#include <bits/stdc++.h>
using namespace std;

const int MOD = 2016;

void chmod(int &n) {
  n = ((n % MOD) + MOD) % MOD;
}

struct matrix {
  int n, m;
  vector<vector<int>> mat;
  matrix(int n, int m): n(n), m(m), mat(n, vector<int>(m)) {}
  vector<int>& operator[](int i) { return mat[i]; }
};

matrix ident(int n) {
  matrix ret(n, n);
  for (int i = 0; i < n; i++) {
    ret[i][i] = 1;
  }
  return ret;
}

matrix operator*(matrix a, matrix b) {
  assert(a.m == b.n);
  matrix c(a.n, b.m);
  for (int i = 0; i < a.n; i++)
  for (int j = 0; j < b.m; j++)
  for (int k = 0; k < a.m; k++) {
    c[i][j] += a[i][k] * b[k][j];
    chmod(c[i][j]);
  }
  return c;
}

matrix binpow(matrix a, long long b) {
  assert(a.n == a.m);
  if (b == 0) return ident(a.n);
  matrix t = binpow(a, b / 2);
  if (b % 2) return t * t * a;
  return t * t;
}

int up(long long n) {
  if (n == 1) return 1;
  matrix a(1, 4), b(4, 4);
  a[0] = { 1, 0, 1, 1};
  b[0] = { 2, 1, 0, 0};
  b[1] = {-1, 0, 0, 0};
  b[2] = { 1, 0, 1, 0};
  b[3] = { 1, 0, 1, 1};
  return (a * binpow(b, n - 1))[0][0];
}

int down(long long n) {
  if (n == 1) return 0;
  matrix a(1, 5), b(5, 5);
  if (n % 2 == 0) {
    a[0] = {1, 0, 4, 4, -3};
  }
  else {
    a[0] = {3, 0, 6, 4, -3};
  }
  b[0] = { 2, 1, 0, 0, 0};
  b[1] = {-1, 0, 0, 0, 0};
  b[2] = { 1, 0, 1, 0, 0};
  b[3] = { 1, 0, 1, 1, 0};
  b[4] = { 1, 0, 0, 0, 1};
  return (a * binpow(b, (n - 2) / 2))[0][0];
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  long long n; cin >> n;
  cout << up(n) + down(n) << '\n';
}
