#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

void Main() {
  vector<int> a(12);
  for (auto &i : a) cin >> i;
  if (a[0] == 0) exit(0);
  sort(a.begin(), a.end());
  for (int i = 0; i < 12; i += 4) {
    for (int j = 1; j < 4; j++) {
      if (a[i] != a[i + j]) {
        cout << "no" << endl;
        return;
      }
    }
  }
  cout << "yes" << endl;
}

signed main() {
  // freopen("in" , "r", stdin );
  cin.tie(0)->sync_with_stdio(0);
  while (true) Main();
}
