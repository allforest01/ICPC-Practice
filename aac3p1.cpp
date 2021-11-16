#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  bool flag1 = b > a;
  bool flag2 = d > c;
  if (flag1 && flag2) {
    printf("Go to the department store\n");
  }
  else if (flag1) {
    printf("Go to the grocery store\n");
  }
  else if (flag2) {
    printf("Go to the pharmacy\n");
  }
  else {
    printf("Stay home\n");
  }
}
