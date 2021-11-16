#include <bits/stdc++.h>
using namespace std;

int query(int n) {
  cout << n << '\n';
  fflush(stdout);
  int r; cin >> r;
  return r;
}

void Main() {
  int n, k;
  cin >> n >> k;
  vector<int> q(n + 1);
  q[0] = 0; q[1] = 1;
  for (int i = 2; i < n; i++) {
    q[i] = i ^ (i - 1);
  }
  for (int i = 0; i < n; i++) {
    int r = query(q[i]);
    if (r == 1) return;
  }
}

int main() {
  int T; cin >> T;
  while (T--) Main();
}
