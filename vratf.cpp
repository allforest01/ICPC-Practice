#include <bits/stdc++.h>
using namespace std;

int n, k;
int cnt = 0;

void split(int n) {
  if (n > k && (n + k) % 2 == 0) {
    split((n + k) / 2);
    split((n - k) / 2);
    return;
  }
  cnt++;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> k;
  split(n);
  cout << cnt << '\n';
}
