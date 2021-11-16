#include <bits/stdc++.h>
using namespace std;

const int N = 100;

long long a[N], ma[N];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  ma[0] = 1000;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    ma[i] = ma[i - 1];
    for (int j = 1; j < i; j++) {
      if (a[i] > a[j]) {
        ma[i] = max(ma[i], (ma[j] / a[j]) * a[i] + (ma[j] % a[j]));
      }
    }
  }
  cout << ma[n] << '\n';
}
