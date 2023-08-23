#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int a, b;
  cin >> a >> b;
  vector<string> s = {"TroyMartian", "VladSaturnian", "GraemeMercurian"};
  if (a >= 3 && b <= 4) cout << s[0] << '\n';
  if (a <= 6 && b >= 2) cout << s[1] << '\n';
  if (a <= 2 && b <= 3) cout << s[2] << '\n';
}
