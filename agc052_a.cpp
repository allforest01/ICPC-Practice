#include <bits/stdc++.h>
using namespace std;

void Main() {
  int n; cin >> n;
  string s1, s2, s3;
  cin >> s1 >> s2 >> s3;
  for (int i = 0; i < n; i++) {
    cout << s1[n - 1];
  }
  for (int i = 0; i < n; i++) {
    cout << (char)(1 - (s1[n - 1] - '0') + '0');
  }
  cout << s1[n - 1] << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
