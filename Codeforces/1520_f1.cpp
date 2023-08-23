#include <bits/stdc++.h>
using namespace std;

int query(int x) {
  cout << "? 1 " << x << '\n';
  fflush(stdout);
  int ret;
  cin >> ret;
  return ret;
}

int answer(int x) {
  cout << "! " << x << '\n';
  fflush(stdout);
  exit(0);
}

int main() {
  int n, t, k;
  cin >> n >> t >> k;
  int l = 1, r = n, ans = -1;
  while (l <= r) {
    int x = (l + r) / 2;
    if (x - query(x) >= k) {
      ans = x;
      r = x - 1;
    }
    else l = x + 1;
  }
  answer(ans);
}
