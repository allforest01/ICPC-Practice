#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int m, h;
  cin >> m >> h;
  cout << (h % m ? "No" : "Yes") << '\n';
}
