#include <bits/stdc++.h>
using namespace std;

int main() {
  string a, b;
  cin >> a >> b;
  if (b.size() >= a.size() && b.substr(0, a.size()) == a) {
    cout << "Yes" << '\n';
  }
  else {
    cout << "No" << '\n';
  }
}
