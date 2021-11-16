#include <bits/stdc++.h>
using namespace std;

void Main() {
  long long n, a, b;
  cin >> n >> a >> b;
  long long t = 1;
  while (t <= n) {
    if ((n - t) % b == 0) {
      cout << "Yes" << '\n';
      return;
    }
    if (a == 1) break;
    else t *= a;
  }
  cout << "No" << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
