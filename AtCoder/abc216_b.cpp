#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<array<string,2>> a(n);
  for (auto &i : a) cin >> i[0] >> i[1];
  int cnt = 0;
  for (int i = 0; i + 1 < n; i++)
  for (int j = i + 1; j < n; j++) {
    if (a[i] == a[j]) cnt++;
  }
  cout << (cnt ? "Yes" : "No") << '\n';
}
