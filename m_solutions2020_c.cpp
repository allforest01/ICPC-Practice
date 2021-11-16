#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto &i : a) cin >> i;
  for (int i = k; i < n; i++) {
    if (a[i] > a[i - k]) {
      cout << "Yes" << '\n';
    }
    else {
      cout << "No" << '\n';
    }
  }
}
