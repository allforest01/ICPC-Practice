#include <bits/stdc++.h>
using namespace std;

const int X = 1e6 + 5;

bool isPrime[X];

int main() {
  for (int i = 2; i < X; i++) {
    isPrime[i] = true;
  }
  for (int i = 2; i < X; i++) {
    if (!isPrime[i]) continue;
    for (int j = i * 2; j < X; j += i) {
      isPrime[j] = false;
    }
  }
  int n, x;
  cin >> n >> x;
  vector<int> a(n + 1), b(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    b[i] = b[i - 1];
    if (2 <= a[i] && a[i] <= x && isPrime[a[i]]) b[i]++;
  }
  int ans = 1e9;
  for (int i = 1; i + b[n] - 1 <= n; i++) {
    ans = min(ans, b[n] - (b[i + b[n] - 1] - b[i - 1]));
  }
  cout << ans << '\n';
}