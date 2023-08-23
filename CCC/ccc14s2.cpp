#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<string> a(n), b(n);
  for (auto &i : a) cin >> i;
  for (auto &i : b) cin >> i;
  map<string,string> mem;
  for (int i = 0; i < n; i++) {
    mem[a[i]] = b[i];
  }
  for (int i = 0; i < n; i++) {
    if (mem[b[i]] != a[i] || mem[b[i]] == b[i]) {
      cout << "bad" << '\n';
      return 0;
    }
  }
  cout << "good" << '\n';
}
