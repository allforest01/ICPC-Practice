#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<int> a(n);
  for (auto &i : a) cin >> i;
  int ans = 0;
  for (int i = 0; i < (int) a.size(); i++) {
    for (int j = (int) a.size() - 1; j > i; j--) {
      if (a[j] < a[j - 1]) {
        swap(a[j], a[j - 1]);
        ans++;
      }
    }
  }
  for (int i = 0; i < (int) a.size(); i++) {
    cout << a[i] << " \n"[i + 1 == (int) a.size()];
  }
  cout << ans << '\n';
}
