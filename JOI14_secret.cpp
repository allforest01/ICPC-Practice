
#include "secret.h"
using namespace std;

const int MAX_N = 1005;

int a[MAX_N], dat[15][MAX_N], mask[MAX_N];

void divi(int l, int r, int lev) {
  if (l == r) return;
  int m = (l + r) / 2;
  dat[lev][m] = a[m];
  for (int i = m - 1; i >= l; i--) {
    dat[lev][i] = Secret(a[i], dat[i + 1][lev]);
  }
  dat[m + 1][lev] = a[m + 1];
  for (int i = m + 2; i <= r; i++) {
    dat[i][lev] = Secret(dat[i - 1][lev], a[i]);
  }
  for (int i = m + 1; i <= r; i++) {
    mask[i] ^= (1 << lev);
  }
  divi(l, m, lev + 1);
  divi(m + 1, r, lev + 1);
}

void Init(int N, int A[]) {
  n = N;
  for (int i = 0; i < N; i++) {
    a[i] = A[i];
  }
  divi(0, n - 1, 0);
}

int Query(int L, int R) {
  if (L == R) return a[L];
  int bits = __builtin_ctz(mask[L] ^ mask[R]);
  return Secret(dat[L][bits], dat[R][bits]);
}
