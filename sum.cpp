#include <bits/stdc++.h>
using namespace std;

pair<bool,string> div(string s, int n) {
  stringstream ss;
  string t = to_string(n);
  int i = 0, d = 0;
  while (i < (int) s.size()) {
    d = d * 10 + (s[i] - '0');
    int j = i;
    while (j < (int) s.size() && d < n) {
      j++;
      d = d * 10 + (s[j] - '0');
    }
    if (j == (int) s.size()) return {false, ""};
    if (i == 0) ss << d / n;
    else ss << setw(j - i + 1) << setfill('0') << d / n;
    d = d % n;
    i = j + 1;
  }
  if (d != 0) return {false, ""};
  return {true, ss.str()};
}

int main() {
  int n; cin >> n;
  vector<string> s(10);
  for (int i = 1; i <= 1e3; i++) {
    for (int j = 1; j <= 9; j++) {
      s[j] += (char)(j + '0');
      auto t = div(s[j], n);
      if (t.first) {
        cout << t.second << '\n';
        return 0;
      }
    }
  }
  cout << -1 << '\n';
}
