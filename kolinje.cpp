#include <bits/stdc++.h>
using namespace std;

const int NN = 1000000;
const double GG = 1000000;

int a[NN], b[NN];

void to_bin(double decker) {
  unsigned char * desmond = (unsigned char *) & decker;
  for (int i = 0; i < sizeof (double); i++) {
    printf ("%02X ", desmond[i]);
  }
  printf ("\n");
}

int main () {
  freopen("in", "r", stdin);
  int n;
  scanf("%d", &n);
  int sa = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", a + i, b + i);
    sa += b[i];
  }
  double dg = 0, gg = GG;
  for (int i = 1; i < n; ++i) {
    int rb = b[i - 1] - b[i];
    int ra = a[i] - a[i - 1];
    if (rb == 0 && ra > 0) {
      printf("-1\n");
      return 0;
    }
    if (rb > 0) dg = max(dg, (double)ra / (double)rb);
    if (rb < 0) gg = min(gg, (double)ra / (double)rb);
  }
  cout << dg << ' ' << gg << endl;
  cout << sa << ' ' << (dg + gg) / 2 << endl;
  double s = (dg + gg) / 2;
  cout << fixed << setprecision(10) << s << '\n';
  to_bin(sa); to_bin(s);
  if ((dg < gg + 1e-9))
    printf("%.12f\n", sa * s);
  else
    printf("-1\n");
}
