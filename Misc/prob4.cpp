#include <bits/stdc++.h>
using namespace std;

pair<bool,string> div(string s, int n) {
  string t = to_string(n);
  int i = 0, d = 0;
  stringstream ss;
  while (i < (int) s.size()) {
    d *= 10;
    int j = i;
    while (j < (int) s.size() && d + stoi(s.substr(i, j - i + 1)) < n) {
      j++;
      d *= 10;
    }
    if (j == (int) s.size()) return {false, ""};
    int k = d + stoi(s.substr(i, j - i + 1));
    if (i == 0) ss << k / n;
    else ss << setw(j - i + 1) << setfill('0') << k / n;
    d = k % n;
    i = j + 1;
  }
  return {d == 0, ss.str()};
}

int main() {
  int n; cin >> n;
  vector<string> s(10);
  for (int i = 1; i <= 1e2; i++) {
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
