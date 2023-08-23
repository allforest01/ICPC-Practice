#include <bits/stdc++.h>
using namespace std;
 
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int q; cin >> q;
  while (q--) {
    long long k; cin >> k;
    long long i = 1, c = 1;
    while (k > i * 9 * c) {
      k -= i * 9 * c;
      i *= 10;
      c++;
    }
    long long t = i + (k - 1) / c;
    string s = to_string(t);
    cout << s[(k - 1) % c] << '\n';
  }
}