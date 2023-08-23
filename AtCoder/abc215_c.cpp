#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  string s; int k;
  cin >> s >> k;
  sort(s.begin(), s.end());
  for (int i = 1; i < k; i++) {
    next_permutation(s.begin(), s.end());
  }
  cout << s << '\n';
}
