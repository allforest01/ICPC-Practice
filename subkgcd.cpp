#include <bits/stdc++.h>
using namespace std;

const int A = 2000005;

int n, k;
int s[A];

bool check(int x) {
  int i = 0, cnt = 0;
  while (i + k < A) {
    cnt += s[min(i + k, i + x - 1)] - s[i - 1];
    i += x;
  }
  return cnt == n;
}

int main() {
  cin >> n >> k;
  int mi = A;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    s[x]++;
    mi = min(mi, A);
  }
  for (int i = 1; i < A; i++) {
    s[i] += s[i - 1];
  }
  for (int i = mi; i >= 1; i--) {
    if (check(i)) {
      cout << i << '\n';
      return 0;
    }
  }
}
