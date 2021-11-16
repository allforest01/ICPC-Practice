#include <bits/stdc++.h>
using namespace std;

int ans[10000000];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  for (int i = 1; i <= 100; i++)
  for (int j = 1; j <= 100; j++)
  for (int k = 1; k <= 100; k++) {
    ans[i * i + j * j + k * k + i * j + j * k + k * i]++;
  }
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << '\n';
  }
}
