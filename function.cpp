#include <stdio.h>

// <kieu du lieu> <ten ham>(<danh sach tham so hoac tham tri>) {
  // noi dung ham
  // return de tra ve
// }

void inc(int &b, int &c) {
  // printf("inc  &a = %x\n", &a);
  b++;
  c++;
}

int main() {
  int a, b;
  printf("a b = ");
  scanf("%d %d", &a, &b);
  inc(a, b);
  printf("%d %d\n", a, b);
}
