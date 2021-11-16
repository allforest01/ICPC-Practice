#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int a[N];

void rev(int l, int r) {
  for (int i = 0; i <= (r - l) / 2; i++) {
    swap(a[l + i], a[r - i]);
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  freopen("swap.in" , "r", stdin );
  freopen("swap.out", "w", stdout);
  int n, k, l1, r1, l2, r2;
  cin >> n >> k >> l1 >> r1 >> l2 >> r2;
  for (int i = 1; i <= n; i++) {
    a[i] = i;
  }
  int t = 0;
  while (true) {
    t++;
    rev(l1, r1);
    rev(l2, r2);
    if (is_sorted(a + 1, a + n + 1)) break;
  }
  k %= t;
  for (int i = 1; i <= k; i++) {
    rev(l1, r1);
    rev(l2, r2);
  }
  for (int i = 1; i <= n; i++) {
    cout << a[i] << '\n';
  }
}
