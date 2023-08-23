#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("word.in" , "r", stdin );
  freopen("word.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  int len = 0;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    if (len + s.size() > k) {
      cout << '\n';
      len = 0;
    }
    if (len) cout << ' ';
    cout << s;
    len += s.size();
  }
  cout << '\n';
}
