#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x).size()

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  string s;
  cin >> s;
  vector<char> v;
  for (int i = 0; i < n; i++) {
    if (sz(v) >= 2 && v[sz(v) - 2] == 'f' && v[sz(v) - 1] == 'o' && s[i] == 'x') {
      v.pop_back();
      v.pop_back();
    }
    else v.push_back(s[i]);
  }
  cout << sz(v) << '\n';
}
