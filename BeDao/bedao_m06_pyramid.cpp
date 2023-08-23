#include <bits/stdc++.h>
using namespace std;

int main() {
  double X, Y;
  cin >> X >> Y;
  double b = - (Y + X);
  double c = Y * Y - X * X;
  double delta = b * b - c;
  double x1 = -b + sqrt(delta);
  double x2 = -b - sqrt(delta);
  double a1 = x1, b1 = Y - x1, c1 = X + x1;
  double a2 = x2, b2 = Y - x2, c2 = X + x2;
  if (a1 > b1) swap(a1, b1);
  if (a2 > b2) swap(a2, b2);
  cout << fixed << setprecision(10);
  if (a1 > 0 && b1 > 0 && c1 > 0) {
    cout << a1 << ' ' << b1 << ' ' << c1 << '\n';
  }
  else {
    cout << a2 << ' ' << b2 << ' ' << c2 << '\n';
  }
}