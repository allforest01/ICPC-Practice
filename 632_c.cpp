#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<string> s(n);
  for (auto &i : s) cin >> i;
  sort(s.begin(), s.end(), [](string &a, string &b){
    return a + b < b + a;
  });
  for (auto &i : s) cout << i;
  cout << '\n';
}
