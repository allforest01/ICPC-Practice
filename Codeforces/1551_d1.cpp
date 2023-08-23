#include <bits/stdc++.h>
using namespace std;

void Main() {
  int n, m, k;
  cin >> n >> m >> k;
  if (k && m == 1) {
    cout << "NO" << '\n';
    return;
  }
  if (n % 2 == 1 && m % 2 == 0) {
    int t = m / 2;
    if (k % t == 0 && (k / t) % 2) {
      cout << "YES" << '\n';
    }
    else {
      cout << "NO" << '\n';
    }
    return;
  }
  if (k > (n / 2 * 2) * (m / 2 * 2)) {
    cout << "NO" << '\n';
    return;
  }
  if (k % 2 == 0) {
    cout << "YES" << '\n';
  }
  else {
    cout << "NO" << '\n';
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
