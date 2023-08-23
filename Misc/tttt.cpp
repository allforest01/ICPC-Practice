#include <bits/stdc++.h>
using namespace std;

char a[3][3];
set<pair<char,char>> cnt;

void check(char c1, char c2, char c3) {
  set<char> s;
  s.insert(c1);
  s.insert(c2);
  s.insert(c3);
  if (s.size() == 1) cnt.insert(make_pair(*s.begin(), *s.begin()));
  if (s.size() == 2) cnt.insert(make_pair(*s.begin(), *next(s.begin())));
}

int main() {
  freopen("tttt.in" , "r", stdin );
  freopen("tttt.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  for (int i = 0; i < 3; i++)
  for (int j = 0; j < 3; j++) {
    cin >> a[i][j];
  }
  for (int i = 0; i < 3; i++) {
    check(a[i][0], a[i][1], a[i][2]);
    check(a[0][i], a[1][i], a[2][i]);
  }
  check(a[0][0], a[1][1], a[2][2]);
  check(a[0][2], a[1][1], a[2][0]);
  int cnt1 = 0, cnt2 = 0;
  for (auto &i : cnt) {
    if (i.first == i.second) cnt1++;
    else cnt2++;
  }
  cout << cnt1 << '\n';
  cout << cnt2 << '\n';
}
