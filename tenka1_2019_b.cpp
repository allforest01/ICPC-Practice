#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, k; string s;
  cin >> n >> s >> k;
  for (auto &i : s) {
    if (i != s[k - 1]) i = '*';
  }
  cout << s << '\n';
}
