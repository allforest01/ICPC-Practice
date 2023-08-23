#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    printf("%d X %d = %d\n", n, i, n * i);
  }
}
