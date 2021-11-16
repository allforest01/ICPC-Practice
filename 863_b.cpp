#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  n *= 2;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  sort(a.begin(), a.end());
  int ans = INT_MAX;
  for (int i = 0; i + 1 < n; i++)
  for (int j = i + 1; j < n; j++) {
    vector<int> v;
    for (int k = 0; k < n; k++) {
      if (k != i && k != j) {
        v.push_back(a[k]);
      }
    }
    int cal = 0;
    for (int k = 0; k < n - 2; k += 2) {
      cal += abs(v[k] - v[k + 1]);
    }
    ans = min(ans, cal);
  }
  cout << ans << '\n';
}
