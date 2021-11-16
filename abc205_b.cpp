#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<int> a(n);
  for (auto &i : a) cin >> i;
  sort(a.begin(), a.end());
  bool flag = 1;
  for (int i = 0; i < n; i++) {
    if (a[i] != i + 1) {
      flag = 0;
      break;
    }
  }
  if (flag) {
    cout << "Yes" << '\n';
  }
  else {
    cout << "No" << '\n';
  }
}
